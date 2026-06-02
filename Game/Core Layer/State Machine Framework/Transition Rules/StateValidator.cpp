#include "StateValidator.h"

#include "StateValidator.h"
 
StateValidator::StateValidator()
{
    // ── Boot ──────────────────────────────────────────────────────────────
    RegisterTransition(EGlobalState::Loading,   EGlobalState::MainMenu);
 
    // ── MainMenu ──────────────────────────────────────────────────────────
    RegisterTransition(EGlobalState::MainMenu,  EGlobalState::Loading);   // novo jogo / continue
    RegisterTransition(EGlobalState::MainMenu,  EGlobalState::Garage);
 
    // ── Garage ────────────────────────────────────────────────────────────
    RegisterTransition(EGlobalState::Garage,    EGlobalState::FreeRoam);
    RegisterTransition(EGlobalState::Garage,    EGlobalState::MainMenu);
 
    // ── FreeRoam ──────────────────────────────────────────────────────────
    RegisterTransition(EGlobalState::FreeRoam,  EGlobalState::Race);
    RegisterTransition(EGlobalState::FreeRoam,  EGlobalState::Pursuit);
    RegisterTransition(EGlobalState::FreeRoam,  EGlobalState::Garage);
    RegisterTransition(EGlobalState::FreeRoam,  EGlobalState::Cutscene);
    RegisterTransition(EGlobalState::FreeRoam,  EGlobalState::Loading);   // troca de distrito
 
    // ── Race ──────────────────────────────────────────────────────────────
    RegisterTransition(EGlobalState::Race,      EGlobalState::FreeRoam);  // corrida terminada/abortada
    RegisterTransition(EGlobalState::Race,      EGlobalState::Pursuit);   // policia entra durante corrida
    RegisterTransition(EGlobalState::Race,      EGlobalState::Cutscene);  // cutscene de vitória
 
    // ── Pursuit ───────────────────────────────────────────────────────────
    RegisterTransition(EGlobalState::Pursuit,   EGlobalState::FreeRoam);  // escapou / capturado
    RegisterTransition(EGlobalState::Pursuit,   EGlobalState::Race);      // corrida começa durante pursuit
    RegisterTransition(EGlobalState::Pursuit,   EGlobalState::Cutscene);
 
    // ── Cutscene ──────────────────────────────────────────────────────────
    RegisterTransition(EGlobalState::Cutscene,  EGlobalState::FreeRoam);
    RegisterTransition(EGlobalState::Cutscene,  EGlobalState::Race);
    RegisterTransition(EGlobalState::Cutscene,  EGlobalState::MainMenu);
 
    // ── Pause (qualquer estado pode pausar → Paused) ──────────────────────
    // O Pause() e Unpause() na GlobalStateMachine tratam isso explicitamente,
    // mas registramos as arestas aqui para que o Validator as reconheça.
    RegisterTransition(EGlobalState::FreeRoam,  EGlobalState::Paused);
    RegisterTransition(EGlobalState::Race,      EGlobalState::Paused);
    RegisterTransition(EGlobalState::Pursuit,   EGlobalState::Paused);
    RegisterTransition(EGlobalState::Garage,    EGlobalState::Paused);
 
    // Paused → qualquer (gerenciado por Unpause que usa PrePauseState)
    RegisterTransition(EGlobalState::Paused,    EGlobalState::FreeRoam);
    RegisterTransition(EGlobalState::Paused,    EGlobalState::Race);
    RegisterTransition(EGlobalState::Paused,    EGlobalState::Pursuit);
    RegisterTransition(EGlobalState::Paused,    EGlobalState::Garage);
    RegisterTransition(EGlobalState::Paused,    EGlobalState::MainMenu);  // "Voltar ao Menu" do pause
}
 
bool StateValidator::IsTransitionValid(
    EGlobalState From,
    EGlobalState To
) const
{
    return ValidTransitions.count({ From, To }) > 0;
}
 
void StateValidator::RegisterTransition(
    EGlobalState From,
    EGlobalState To
)
{
    ValidTransitions.insert({ From, To });
}
 