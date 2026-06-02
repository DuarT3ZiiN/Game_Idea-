 
#include <cstdint>
 
// Estados locais — ativos simultaneamente, independentes entre si.
// Seção 3.3.2 do README.
//
// Estados locais NÃO são exclusivos: NitroActive e DriftChain
// podem estar ativos ao mesmo tempo, por exemplo.
//
// Adicionados em relação à versão anterior:
//   - FinalLap          : última volta (Circuit Rules 1.1.2.2)
//   - DragLaunch        : janela de largada no Drag (1.1.2.4)
//   - DragShiftWindow   : janela de shift perfeito no Drag (1.1.2.4.4)
//   - PursuitSearchMode : polícia em modo busca (1.2.6)
//   - Cooldown          : contagem regressiva para escape confirmado (1.2.2)
 
enum class ELocalState : uint8_t
{
    None = 0,
 
    // ── Corrida ──────────────────────────────────────
    Countdown,          // Contagem 3-2-1-GO
    FinalLap,           // Última volta (Circuit)
 
    // ── Drift (1.1.2.3) ──────────────────────────────
    DriftChain,         // Combo de drift ativo
    DriftEntry,         // Janela de entrada de drift
 
    // ── Drag (1.1.2.4) ───────────────────────────────
    DragLaunch,         // Janela de launch (clutch + RPM)
    DragShiftWindow,    // Janela de perfect shift
 
    // ── Veículo ──────────────────────────────────────
    NitroActive,        // Nitro consumindo
 
    // ── Perseguição (1.2.2) ──────────────────────────
    PoliceEscalation,   // Reforços chamados
    PursuitSearchMode,  // Polícia buscando (perdeu linha de visão)
    PursuitCooldown,    // Timer de cooldown antes de Escaped
};
 