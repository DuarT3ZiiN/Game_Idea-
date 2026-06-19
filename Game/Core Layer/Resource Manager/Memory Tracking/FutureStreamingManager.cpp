#include "FutureStreamingManager.h"

#include <algorithm>

void FutureStreamingManager::RequestAsset(const StreamingRequest& Request)
{
    PendingRequests.push_back(Request);
}

void FutureStreamingManager::CancelByDistrict(uint32_t DistrictID)
{
    PendingRequests.erase(
        std::remove_if(
            PendingRequests.begin(),
            PendingRequests.end(),
            [DistrictID](const StreamingRequest& R)
            {
                return R.DistrictID == DistrictID;
            }
        ),
        PendingRequests.end()
    );
}

void FutureStreamingManager::Update(float DeltaTime)
{
    // TODO: processar PendingRequests via AsyncJobManager
    // Ordenar por Priority desc, submeter os bImmediate primeiro
    (void)DeltaTime;
}

uint32_t FutureStreamingManager::GetPendingCount() const
{
    return static_cast<uint32_t>(PendingRequests.size());
}