// LocalStateMachine gerencia estados locais simultâneos.
//
// Melhorias em relação à versão anterior:
//   - GetActiveDuration() — tempo em segundos que um estado está ativo
//     (usado por DriftChain score, PursuitCooldown timer, etc.)
//   - ActivateExclusive() — ativa um estado e desativa outro
//     (ex: DragLaunch e DragShiftWindow são mutuamente exclusivos)
//   - Tick() — permite que estados com timeout se desativem sozinhos
//   - Callbacks OnActivated / OnDeactivated para integração com EventBus
 
class LocalStateMachine
{
public:
 
    void ActivateState  (ELocalState State);
    void DeactivateState(ELocalState State);
 
    // Desativa FromState e ativa ToState atomicamente
    void ActivateExclusive(ELocalState FromState, ELocalState ToState);
 
    bool IsStateActive(ELocalState State) const;
 
    // Tempo (segundos) desde que o estado foi ativado. Retorna 0 se inativo.
    double GetActiveDuration(ELocalState State, double CurrentTime) const;
 
    // Deve ser chamado por RuntimeStateCoordinator a cada frame
    void Tick(float DeltaTime);
 
    // Callbacks opcionais
    void SetOnActivated  (LocalStateCallback Callback);
    void SetOnDeactivated(LocalStateCallback Callback);
 
private:
 
    LocalStateContext   Context;
    double             CurrentTime = 0.0;
 
    LocalStateCallback OnActivated;
    LocalStateCallback OnDeactivated;
};
 