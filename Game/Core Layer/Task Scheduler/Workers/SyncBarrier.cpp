#include "SyncBarrier.h"

SyncBarrier::SyncBarrier(
    uint32_t Count
)
{
    Threshold = Count;
    Counter = Count;
}

void SyncBarrier::Wait()
{
    std::unique_lock<
        std::mutex
    > Lock(Mutex);

    Counter--;

    if (Counter == 0)
    {
        Counter = Threshold;

        CV.notify_all();

        return;
    }

    CV.wait(
        Lock,
        [&]()
        {
            return Counter
                == Threshold;
        }
    );
}

