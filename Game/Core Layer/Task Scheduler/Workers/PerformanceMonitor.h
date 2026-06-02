#pragma once

#include <unordered_map>
#include <string>
#include <mutex>
#include <cstdint>

// PerformanceMonitor rastreia tempo médio de execução por sistema/job.
//
// Melhoria em relação à versão anterior:
//   - Média móvel exponencial (EMA) — GetAverageTime() retorna valor suavizado
//     em vez da última leitura bruta
//   - Thread-safe via mutex (WorkerThreads escrevem de múltiplas threads)
//   - GetPeakTime() — tempo máximo registrado (útil para detectar spikes)
//   - Reset() — limpa picos entre frames sem apagar a média

struct SystemTimingData
{
    double AverageMS = 0.0;
    double PeakMS    = 0.0;
    double Alpha     = 0.1;  // fator EMA: 0.1 = suave, 0.5 = reativo
};

class PerformanceMonitor
{
public:

    // Registra uma nova medição — chamado pela WorkerThread
    void RegisterTime(const std::string& SystemName, double TimeMS);

    // Tempo médio suavizado por EMA
    double GetAverageTime(const std::string& SystemName) const;

    // Pico desde o último ResetPeaks()
    double GetPeakTime(const std::string& SystemName) const;

    // Zera picos — chame uma vez por segundo ou por frame
    void ResetPeaks();

private:

    mutable std::mutex                              Mutex;
    std::unordered_map<std::string, SystemTimingData> Times;
};