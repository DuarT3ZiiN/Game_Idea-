#pragma once
 
// StateTransitionRule<TState> descreve uma aresta válida no grafo de estados.
// O StateValidator mantém um vetor dessas regras e as consulta em IsTransitionValid().
 
template<typename TState>
struct StateTransitionRule
{
    TState From;
    TState To;
};
 