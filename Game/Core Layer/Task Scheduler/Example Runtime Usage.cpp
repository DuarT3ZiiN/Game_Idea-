// ── Example Runtime Usage — Task Scheduler ───────────────────────────────────

TaskScheduler Scheduler;

// Inicializa com detecção automática de threads (hardware_concurrency - 1)
Scheduler.Initialize();

// Registra budgets por sistema (seção 3.4.3)
Scheduler.GetBudgetManager().RegisterBudget("VehiclePhysics", 4.0);  // 4ms
Scheduler.GetBudgetManager().RegisterBudget("AISimulation",   3.0);  // 3ms
Scheduler.GetBudgetManager().RegisterBudget("TrafficUpdate",  2.0);  // 2ms

// ── Submissão de job único ────────────────────────────────────────────────────

Job VehiclePhysics;
VehiclePhysics.Priority  = EJobPriority::Critical;
VehiclePhysics.DebugName = "VehiclePhysics";
VehiclePhysics.Execute   = []()
{
    // Atualizar física de veículos
};
VehiclePhysics.OnComplete = [](JobID ID)
{
    // Notificar sistemas dependentes (ex: Camera, Audio)
};

Scheduler.Submit(VehiclePhysics);

// ── Batch de jobs paralelos (ex: IA de 8 viaturas) ───────────────────────────

Job AIJobs[8];
for (uint32_t i = 0; i < 8; ++i)
{
    AIJobs[i].Priority  = EJobPriority::High;
    AIJobs[i].DebugName = "PoliceAI";
    AIJobs[i].Execute   = [i]()
    {
        // Processar IA da viatura i
    };
}

Scheduler.SubmitBatch(AIJobs, 8);

// ── Polling de conclusão no main thread ──────────────────────────────────────

// Aguardar job crítico sem bloquear (polling não-invasivo)
while (!VehiclePhysics.bCompleted->load(std::memory_order_acquire))
{
    // Pode fazer outras coisas no main thread
}

// ── Parallelismo de dados com JobDistributor ─────────────────────────────────

const uint32_t VehicleCount = 1000;
const uint32_t WorkerCount  = Scheduler.GetPerformanceMonitor()
    // ... ou simplesmente use hardware_concurrency
    , 0; // placeholder

auto Chunks = JobDistributor::SplitWork(VehicleCount, 6);

for (const auto& [Start, End] : Chunks)
{
    Job ChunkJob;
    ChunkJob.Priority  = EJobPriority::Critical;
    ChunkJob.DebugName = "VehiclePhysics_Chunk";
    ChunkJob.Execute   = [Start, End]()
    {
        for (uint32_t i = Start; i < End; ++i)
        {
            // Processar veículo i
        }
    };

    Scheduler.Submit(ChunkJob);
}

// ── Fim do frame ──────────────────────────────────────────────────────────────

Scheduler.EndFrame(); // ResetFrame() + ResetPeaks() + Clear dependencies

// ── Consulta de performance (Debug Tools 3.13) ────────────────────────────────

double PhysicsAvg  = Scheduler.GetPerformanceMonitor().GetAverageTime("VehiclePhysics");
double PhysicsPeak = Scheduler.GetPerformanceMonitor().GetPeakTime("VehiclePhysics");
bool   AIOverBudget = Scheduler.GetBudgetManager().IsOverBudget("AISimulation");

// ── Shutdown ──────────────────────────────────────────────────────────────────

Scheduler.Shutdown(); // sinaliza workers, drena filas, join threads