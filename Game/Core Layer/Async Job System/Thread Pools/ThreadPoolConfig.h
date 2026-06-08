#pragma once

#include <cstdint>
#include <thread>

// ThreadPoolConfig descreve como o pool de workers do BackgroundJobSystem
// deve ser inicializado.
//
// Melhorias em relação à versão anterior:
//   - WorkerCount = 0 → detecta hardware_concurrency automaticamente
//   - QueueCapacity configurável por pool (diferente do ASYNC_QUEUE_CAPACITY global)
//   - bDedicatedSaveWorker — garante que SaveGame sempre tenha um worker exclusivo,
//     evitando que Streaming bloqueie saves (crítico para o seção 3.6 do README)

struct ThreadPoolConfig
{
    // 0 = auto-detect (hardware_concurrency - 1, mínimo 1)
    uint32_t WorkerCount = 0;

    uint32_t QueueCapacity = 1024;

    // Reserva 1 worker exclusivo para jobs do tipo SaveGame
    bool bDedicatedSaveWorker = true;

    static ThreadPoolConfig Default()
    {
        ThreadPoolConfig Config;
        Config.WorkerCount          = 0;
        Config.QueueCapacity        = 1024;
        Config.bDedicatedSaveWorker = true;
        return Config;
    }

    uint32_t ResolvedWorkerCount() const
    {
        if (WorkerCount > 0)
            return WorkerCount;

        const uint32_t HW = std::thread::hardware_concurrency();
        return (HW > 2) ? HW - 2 : 1;
    }
};