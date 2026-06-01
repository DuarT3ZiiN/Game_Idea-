# Engine Architecture

```text
Arquitetura de jogo moderno open-world baseado em:
- Need for Speed Underground 2
- Need for Speed Most Wanted
- Need for Speed Carbon
- Need for Speed Pro Street
- Forza Horizon
```

---

# Fluxo de Dados

```mermaid
graph LR

Game[Game Layer]
    --> Simulation[Simulation Layer]

Simulation
    --> Core[Core Layer]

Core
    --> Presentation[Presentation Layer]

Presentation
    --> Platform[Platform Layer]
```

---

# Layers

<details>
<summary><strong>🎮 Game Layer</strong></summary>

```text
1. Game Layer
├── Race Systems
│   ├── Runtime
│   │   ├── Event Runtime
│   │   ├── Session Manager
│   │   ├── Race Flow
│   │   ├── Participant Manager
│   │   ├── State Machine
│   │   └── Event Pipeline
│   │
│   ├── Rules
│   │   ├── Sprint Rules
│   │   ├── Circuit Rules
│   │   ├── Drift Rules
│   │   ├── Drag Rules
│   │   ├── Canyon Rules
│   │   ├── Time Attack Rules
│   │   └── Tollbooth Rules
│   │
│   ├── AI
│   │   ├── Race Director
│   │   ├── Rubber Banding
│   │   ├── Rival Behaviors
│   │   ├── Tactical Driving
│   │   └── Aggression Profiles
│   │
│   ├── Crew Systems
│   │   ├── Tactical Roles
│   │   ├── Team Coordination
│   │   ├── Communication
│   │   ├── Assist Logic
│   │   ├── Rival Crews
│   │   └── Personality Profiles
│   │
│   ├── Spawn Systems
│   │   ├── Grid Spawn
│   │   ├── Recovery Spawn
│   │   ├── Dynamic Spawn
│   │   └── Streaming Validation
│   │
│   ├── Checkpoint Systems
│   │   ├── Spline Progression
│   │   ├── Checkpoint Validation
│   │   ├── Shortcut Validation
│   │   └── Anti-Cheat Logic
│   │
│   ├── Integrations
│   │   ├── Traffic Adapter
│   │   ├── Police Adapter
│   │   ├── Economy Adapter
│   │   └── Mission Adapter
│   │
│   ├── Rewards
│   │   ├── Cash Rewards
│   │   ├── Reputation Rewards
│   │   ├── Crew Reputation
│   │   └── Unlock System
│   │
│   ├── Telemetry
│   │   ├── Heatmaps
│   │   ├── Difficulty Metrics
│   │   ├── Crash Analytics
│   │   └── AI Performance
│   │
│   └── Online
│       ├── Synchronization
│       ├── Ghost System
│       ├── Match Runtime
│       └── Replication
│
├── Police Systems
│   ├── Director
│   ├── Pursuit Runtime
│   ├── Tactical AI
│   ├── Heat System
│   ├── Spawn System
│   ├── Search System
│   ├── Roadblock System
│   ├── Helicopter System
│   ├── Escalation System
│   ├── Radio System
│   ├── Vehicle Enforcement
│   ├── Jurisdiction System
│   └── World Response
│
├── Career Systems
│   ├── Blacklist
│   ├── Crew Progression
│   ├── Reputation
│   ├── Story Events
│   ├── Unlock Progression
│   └── Event Availability
│
├── Economy Systems
│   ├── Currency
│   ├── Reward Scaling
│   ├── Car Pricing
│   ├── Upgrade Pricing
│   ├── Sponsorships
│   └── Risk/Reward Logic
│
├── Mission Systems
│   ├── Objective Runtime
│   ├── Trigger System
│   ├── Dynamic Events
│   ├── Script Runtime
│   ├── World Events
│   └── Cinematic Hooks
│
├── World Systems
│   ├── Traffic Runtime
│   ├── Civilian AI
│   ├── Pedestrian Logic
│   ├── Ambient Events
│   ├── Day/Night Cycle
│   ├── Weather Runtime
│   └── World Director
│
└── Global Director
    ├── World Pacing
    ├── Dynamic Intensity
    ├── Traffic Density
    ├── Police Pressure
    ├── Audio Intensity
    └── Event Orchestration
```
### Responsibilities

- Race orchestration
- Police pursuits
- Career progression
- Economy
- Missions
- World pacing
- Dynamic events

---

# 1. Game Layer

> Nucleo principal de como o jogo deve funcionar.

---

## Responsável por:

```text
- gameplay orchestration
- regras do jogo
- progressão
- pacing
- experiência cinematográfica
- sistemas de corrida
- polícia
- economia
- carreira
- integração entre sistemas
```

## Não deve:

```text
- conter física bruta
- conter renderer
- conter lógica de hardware
- controlar memória diretamente
```

---

<details>
<summary><strong>1.1 Race Systems</strong></summary>

---

## Overview

```text

Responsável por:
    - gerenciamento de eventos automobilísticos
    - regras de corrida
    - fluxo de corrida
    - progressão de participantes
    - scoring
    - integração com polícia/tráfego
    - replay competitivo
    - pacing competitivo
```

---

## Runtime Structure

```text
Race Systems
├── Runtime
├── Rules
├── Scoring
├── AI
└── Online
```

---

### 1.1.1 Runtime

> Controls active race execution lifecycle.

#### Responsável por:

```text
- execução ativa da corrida
- gerenciamento de sessão
- sincronização de estados
- gerenciamento de participantes
- pipeline de eventos
- authority da corrida

```

#### NÃO deve:

```text
- calcular física
- controlar rendering
- possuir IA global
```

### 1.1.1.1 Event Runtime

#### Apenas:

```text
- inicia evento
- encerra evento
- registra entidades
- controla lifecycle
- distribui eventos
- inicializa módulos necessários
- conecta adapters externos

```

### 1.1.1.2 Session Manager

#### por:

```text
- criar sessão
- destruir sessão
- registrar racers
- validar estados
- controlar reconexões
- coordenar sincronização online

```

### 1.1.1.3 Race Flow

#### Responsável por:

```text
- intro cinematics
- countdown
- transição gameplay/free roam
- finish state
- pós-corrida
- reward dispatch
```

```text
Fluxo:
Load Event
↓
Spawn Participants
↓
Intro Sequence
↓
Countdown
↓
Gameplay
↓
Finish
↓
Rewards
↓
Return To World
```

### 1.1.1.4 Participant Manager

#### Responsável por:

```text
                    - registro de corredores
                    - estado dos racers
                    - DNF
                    - disconnects
                    - ranking parcial
                    - telemetria individual
```

### 1.1.1.5 State Machine

#### Estados:

```text
                    - PRELOAD
                    - INTRO
                    - COUNTDOWN
                    - ACTIVE
                    - FINAL_LAP
                    - FINISHED
                    - ABORTED
```

#### NÃO permitir:

```text
                    - estados inválidos
                    - transições ilegais
                    - race conditions
```

### 1.1.1.6 Event Pipeline

#### Responsável por:

```text
                    - propagação de eventos
                    - hooks
                    - callbacks
                    - replay markers
                    - telemetry hooks
                    - online replication hooks
```

#### Eventos:

```text
                    - OnRaceStart
                    - OnCheckpointReached
                    - OnPlayerCrash
                    - OnPoliceJoined
                    - OnFinalLap
                    - OnRaceFinished
```

---

### 1.1.2 Rules

#### Responsável por:

```text
                - definir comportamento de cada modo
                - validar regras
                - restrições de gameplay
```

#### NÃO deve:

```text
                - controlar IA diretamente
                - manipular câmera
                - alterar física diretamente
```

### 1.1.2.1 Sprint Rules

#### Responsável por:

```text
                    - progress tracking
                    - checkpoint validation
                    - police enabled
                    - traffic enabled
                    - shortcut validation
```

#### Características:

```text
                    - sem voltas
                    - progressão linear
                    - alta velocidade
                    - pressão constante
```

### 1.1.2.2 Circuit Rules

#### Responsável por:

```text
                    - laps
                    - ranking
                    - split times
                    - lap validation
                    - final lap triggers
```

#### Características:

```text
                    - pacing progressivo
                    - consistência
                    - estratégia
```

### 1.1.2.3 Drift Rules

> Baseado diretamente na filosofia do Drift do Need for Speed Pro Street.

#### Overview

---

```text
Filosofia Central

O drift do Pro Street era baseado em:

- entradas agressivas
- peso perceptível
- velocidade alta
- controle parcial
- sensação de risco
- momentum contínuo
```

---

```text
Sensação desejada

O jogador deve sentir:

- carro pesado
- suspensão carregando peso
- traseira tentando escapar
- necessidade de correção constante
- drift extremamente rápido
```

---

#### Estrutura Runtime

```text
Drift Rules
├── Drift Detection
├── Momentum Runtime
├── Weight Transfer Runtime
├── Slip Angle Runtime
├── Drift State Runtime
├── Combo Runtime
├── Transition Runtime
├── Speed Preservation
├── Drift Assist Runtime
├── Stability Runtime
├── Wall Proximity Runtime
├── Style Runtime
├── Camera Director
├── Audio Runtime
└── Replay Hooks
```

---

#### Runtime Pipeline

```text
Approach
    ↓
Weight Transfer
    ↓
Drift Entry
    ↓
Slip Stabilization
    ↓
Combo Runtime
    ↓
Transition
    ↓
Momentum Recovery
    ↓
Combo Finish
    ↓
Score Validation
```

---

### 1.1.2.3.1 Core Philosophy

#### O drift é construído em cima de:

| Sistema | Prioridade |
|---|---|
| Momentum | ALTÍSSIMA |
| Weight Transfer | ALTÍSSIMA |
| Slip Control | ALTÍSSIMA |
| Steering Precision | ALTA |
| Speed Preservation | ALTA |
| Style | MÉDIA |

---

### 1.1.2.3.2 Drift Detection Logic

#### Objetivo

Validar:
- drift legítimo
- perda controlada de tração
- entrada intencional

---

#### Inputs principais

| Input | Uso |
|---|---|
| Steering Angle | direção |
| Yaw Rate | rotação |
| Slip Ratio | perda de tração |
| Lateral Velocity | movimento lateral |
| Weight Transfer | carga lateral |
| Throttle | manutenção |
| Brake | initiation |

---

### 1.1.2.3.3 Entry Validation

```text
IF

Speed > MinimumSpeed
AND
SlipAngle > Threshold
AND
LateralVelocity > MinimumLateral
AND
RearSlipRatio > MinimumSlip

THEN

ENTER DRIFT_ENTRY
```

---

### 1.1.2.3.5 Mede

```text
- lateral load
- suspension compression
- braking transfer
- throttle transfer
- inertia
```

---

### 1.1.2.3.6 Influencia

| Situação | Resultado |
|---|---|
| Transferência suave | estabilidade |
| Transferência agressiva | ângulo maior |
| Transferência excessiva | spinout |
| Transferência lenta | drift morto |

---

### 1.1.2.3.7 Drift Entry Logic

#### Objetivo

Avaliar:
- agressividade
- velocidade
- comprometimento
- initiation quality

---

### 1.1.2.3.8 Tipos de entrada

| Tipo | Característica |
|---|---|
| Feint | transferência rápida |
| Braking Drift | peso frontal |
| Power Over | torque excessivo |
| Clutch Kick | destabilização brusca |

---

### 1.1.2.3.9 Entry Quality

#### Mede

```text
- velocidade
- ângulo inicial
- estabilidade
- fluidez
- controle
```

---

### 1.1.2.3.10 Drift Active Runtime

#### Objetivo

Controlar:
- manutenção do drift
- estabilidade
- momentum
- chaining

---

#### Mede

```text
- slip angle
- speed
- yaw velocity
- throttle modulation
- steering correction
- line quality
```

---

### 1.1.2.3.11 Momentum Runtime

---

#### Mede

```text
- velocidade média
- velocidade lateral
- perda de energia
- continuidade
```

---

#### Penaliza

```text
- excesso de correção
- desaceleração excessiva
- drift “travado”
- quebra de flow
```

---

#### Reward Logic

```text
HighSpeed
+
HighAngle
+
SmoothTransition
+
StableMomentum
=
Massive Score
```

---

### 1.1.2.3.12 Combo Runtime

---

#### Combo inicia

```text
ValidDrift == TRUE
```

---

#### Combo continua

```text
MomentumMaintained == TRUE
AND
DriftAngle > Minimum
AND
Speed > Minimum
```

---

#### Combo quebra

```text
- grip recovery excessiva
- spinout
- wall impact
- ângulo insuficiente
- velocidade muito baixa
```

---

### 1.1.2.3.13 Transition Runtime

#### Mede

```text
- velocidade da troca
- estabilidade
- fluidez
- continuidade do momentum
```

---

#### Transição perfeita

```text
- perda mínima de velocidade
- troca rápida
- controle mantido
- ângulo consistente
```

---

### 1.1.2.3.14 Wall Proximity Runtime

#### Responsável por

```text
- proximity score
- clipping zones
- near misses
- wall pressure
```

---

#### Wall Logic

#### Contato leve

```text
- reduz multiplier
- reduz style
- mantém drift parcialmente
```

---

#### Contato forte

```text
- combo break
- momentum collapse
- score penalty
```

---

### 1.1.2.3.15 Style Runtime

#### Mede

```text
- smoke density
- sustained angle
- transition aggression
- speed commitment
- proximity
```

---

### 1.1.2.3.16 Camera Director

#### Responsável por

```text
- câmera baixa
- FOV agressivo
- shake em transitions
- motion blur forte
- sensação de velocidade extrema
```

---

### 1.1.2.3.17 Audio Runtime

#### Responsável por

```text
- tire scream
- transmission load
- turbo flutter
- engine strain
- backfire
- crowd reaction
```

---

#### Métricas Importantes

| Métrica | Objetivo |
|---|---|
| Drift Angle | agressividade |
| Drift Speed | risco |
| Momentum | flow |
| Transition Quality | técnica |
| Stability | controle |
| Proximity | coragem |
| Combo Duration | consistência |

---

### 1.1.2.4 Drag Rules

> Inspirado diretamente no Drag do Need for Speed Pro Street.

#### Objetivo

O modo Drag deve transmitir:

```text
- risco extremo
- velocidade absurda
- precisão mecânica
- leitura rápida
- punição severa
- feedback audiovisual agressivo
```

---

#### Estrutura Runtime

```text
Drag Rules
├── Burnout Runtime
├── Staging System
├── Launch Controller
├── Shift System
├── Lane System
├── Wheelspin System
├── Nitro Runtime
├── Collision Punishment
├── Speed Trap Logic
├── AI Drag Logic
├── Camera Director
├── Audio Intensity
└── Crash Handler
```

---

#### Responsável por

```text
- launch timing
- burnout control
- tire temperature
- staging validation
- reaction time
- gear shifting
- wheelspin simulation
- lane discipline
- nitro timing
- trap speed
- finish validation
- drag AI pacing
```

---

#### NÃO deve

```text
- utilizar posicionamento tradicional de corrida
- usar rubber banding agressivo
- permitir steering arcade exagerado
- permitir correções irreais em alta velocidade
```

---

#### Filosofia de Gameplay

##### O jogador deve sentir:

```text
- vulnerabilidade
- potência descontrolada
- tensão constante
- risco de destruição
- necessidade de precisão absoluta
```

---

#### Estrutura da Corrida

```text
Burnout
    ↓
Stage
    ↓
Countdown
    ↓
Launch
    ↓
Shift Sequence
    ↓
Nitro Windows
    ↓
Trap Speed
    ↓
Finish
```

---

### 1.1.2.4.1 Burnout Runtime

#### Responsável por

```text
- aquecimento dos pneus
- geração de fumaça
- controle de temperatura
- grip temporário
- feedback audiovisual
```

#### Variáveis

| Variável | Efeito |
|---|---|
| Tire Temperature | aumenta tração |
| Burnout Duration | influencia grip |
| Overheat | reduz eficiência |
| Surface Condition | altera resultado |

---

### 1.1.2.4.2 Staging System

#### Responsável por

```text
- alinhamento no grid
- validação de posição
- controle pré-largada
- sincronização de launch
```

#### Estados

```text
PRE_STAGE
STAGED
READY
INVALID
```

---

### 1.1.2.4.3 Launch Controller

#### Responsável por

```text
- RPM ideal
- clutch simulation
- traction check
- launch quality
- wheelspin trigger
```

#### Resultado da largada

| Qualidade | Resultado |
|---|---|
| Perfect Launch | aceleração máxima |
| Good Launch | pequena perda |
| Bad Launch | wheelspin |
| OverRev | perda severa |

---

### 1.1.2.4.4 Shift System

#### Inspirado diretamente no Pro Street

O shift deve ser:
- extremamente rápido
- altamente técnico
- brutalmente punitivo

---

#### Responsável por

```text
- shift windows
- perfect shifts
- miss shifts
- overrev penalties
- transmission stress
```

#### Estados

```text
PERFECT_SHIFT
GOOD_SHIFT
EARLY_SHIFT
LATE_SHIFT
MISSHIFT
```

---

### 1.1.2.4.5 Lane System

#### Responsável por

```text
- lane validation
- collision detection
- steering limitation
- drift suppression
```

#### Filosofia

O jogador:
- NÃO deve “dirigir normalmente”
- deve sobreviver à aceleração

---

### 1.1.2.4.6 Nitro Runtime

#### Responsável por

```text
- nitro windows
- pressure boosts
- traction destabilization
- timing rewards
```

#### Regras

```text
- nitro cedo demais causa wheelspin
- nitro tardio reduz eficiência
- nitro perfeito gera boost máximo
```

---

### 1.1.2.4.7 Speed Trap Logic

#### Responsável por

```text
- velocidade final
- velocidade média
- trap records
- sector analysis
```

---

### 1.1.2.4.8 AI Drag Logic

#### IA deve:

```text
- errar shifts ocasionalmente
- usar nitro estrategicamente
- defender lane
- reagir ao launch
- possuir personalidade mecânica
```

#### Arquétipos

| Perfil | Característica |
|---|---|
| Precision Driver | shifts perfeitos |
| Aggressive Driver | launch agressivo |
| Nitro Specialist | nitro otimizado |
| Risk Driver | alta chance de crash |

---

### 1.1.2.4.9 Camera Director

#### Responsável por

```text
- câmera agressiva
- shake em shifts
- FOV dinâmico
- sensação de velocidade
- impacto cinematográfico
```

---

### 1.1.2.4.9 Audio Intensity

#### Responsável por

```text
- transmissão
- turbo flutter
- backfire
- tire scream
- nitro pressure
- RPM stress
```

---

#### Sensação desejada

```text
Need for Speed Pro Street:
não parece uma corrida comum.

Parece uma máquina tentando matar o piloto.
```

---

#### Métricas importantes

| Métrica | Objetivo |
|---|---|
| Reaction Time | precisão |
| Shift Accuracy | skill |
| Wheelspin Ratio | controle |
| Trap Speed | performance |
| Nitro Efficiency | otimização |
| Lane Stability | domínio |

---

#### Pacing Ideal

```text
Pré-largada:
tensão psicológica

Launch:
explosão instantânea

Mid-run:
controle caótico

Final:
sobrevivência em alta velocidade
```

### 1.1.2.5 Canyon Rules

#### Responsável por:

```text
                    - duel scoring
                    - gap tracking
                    - edge danger
                    - pressure system
                    - overtake punishments
```

#### Características:

```text
                    - estradas estreitas
                    - IA agressiva
                    - alto risco
                    - pacing psicológico
```

### 1.1.2.6 Time Attack Rules

#### Responsável por:

```text
                    - timer runtime
                    - split sectors
                    - ghost tracking
                    - record validation
```

#### Características:

```text
                    - precisão
                    - otimização de rota
                    - baixa tolerância a erro
```

### 1.1.2.7 Tollbooth Rules

#### Responsável por:

```text
                    - countdown timer
                    - checkpoint extensions
                    - pacing escalation
                    - speed pressure
```

#### Características:

```text
                    - pressão constante
                    - ritmo acelerado
                    - progressão agressiva
```

---

### 1.1.3 AI

#### Responsável por:

```text
                - comportamento competitivo
                - pacing
                - pressão psicológica
                - espetáculo cinematográfico
```

### 1.1.3.1 Race Director
>Esse é o “cérebro cinematográfico”.

#### Controla:

```text
                    - pacing
                    - tension
                    - AI aggression
                    - police escalation
                    - traffic density
                    - soundtrack intensity
                    - cinematic moments
```

#### NÃO deve:

```text
                    - dirigir carros diretamente
                    - controlar física
```

### 1.1.3.2 Rubber Banding

#### NÃO fazer:

```text
                    - boost absurdo de velocidade
```

#### Fazer:

```text
                    - ajuste de agressividade
                    - ajuste de erros da IA
                    - controle de pressão
                    - recuperação cinematográfica
```

### 1.1.3.3 Rival Behaviors

#### Responsável por:

```text
                    - rivalidade dinâmica
                    - targeting
                    - vingança
                    - intimidação
                    - defesa de posição
```

### 1.1.3.4 Tactical Driving

#### Responsável por:

```text
                    - bloqueios
                    - draft
                    - cutoff
                    - defesa
                    - pressão lateral
```

### 1.1.3.5 Aggression Profiles

#### Perfis:

```text
                    - Defensive
                    - Aggressive
                    - Technical
                    - Unstable
                    - Tactical
                    - Reckless
```


### 1.1.4 Crew Systems

#### Responsável por:

```text
                - coordenação em equipe
                - personalidade das crews
                - suporte tático
                - narrativa emergente
```

### 1.1.4.1 Tactical Roles

#### Papéis:

```text
                    - Blocker
                    - Drafter
                    - Scout
                    - Aggressor
```

### 1.1.4.2 Team Coordination

#### Responsável por:

```text
                    - coordenação contextual
                    - decisões cooperativas
                    - troca dinâmica de funções
```

### 1.1.4.3 Communication

#### Responsável por:

```text
                    - rádio
                    - callouts
                    - alertas
                    - informações de tráfego/polícia
```

### 1.1.4.4 Assist Logic

#### Responsável por:

```text
                    - abrir caminho
                    - proteger líder
                    - criar draft
                    - interromper rivais
```

### 1.1.4.5 Rival Crews

#### Responsável por:

```text
                    - identidade de crews
                    - reputação
                    - rivalidades persistentes
```

### 1.1.4.6 Personality Profiles

#### Mede:

```text

                    - agressividade
                    - coragem
                    - disciplina
                    - risco
                    - cooperação
```

---


### 1.1.5 Spawn Systems

#### Responsável por:

```text
                - posicionamento inicial
                - recuperação segura
                - validação espacial
                - controle de spawning dinâmico
                - prevenção de colisões de spawn
```

### 1.1.5.1 Grid Spawn

#### Responsável por:

```text
                    - alinhamento inicial
                    - spacing entre veículos
                    - ordem de largada
                    - validação de pista
```

#### Precisa:

```text
                    - evitar clipping
                    - evitar overlap
                    - respeitar largura da pista
```

### 1.1.5.2 Recovery Spawn

#### Responsável por:

```text
                    - detectar stuck state
                    - detectar capotamento
                    - reposicionar jogador
                    - validar segurança do respawn
```

#### NÃO deve:

```text
                    - permitir exploits
                    - quebrar flow da corrida
```

### 1.1.5.3 Dynamic Spawn

#### Responsável por:

```text
                    - spawn dinâmico de IA
                    - entradas cinematográficas
                    - reforços policiais
                    - racers de evento
```

#### Precisa:

```text
                    - ocorrer fora do campo de visão
                    - respeitar streaming
                    - respeitar tráfego
```

### 1.1.5.4 Streaming Validation

#### Responsável por:

```text
                    - validar região carregada
                    - impedir spawn em unloaded areas
                    - validar memória disponível
```

---


### 1.1.6 Checkpoint Systems

#### Responsável por:

```text

                - progressão
                - validação de rota
                - detecção de exploits
                - controle de atalhos
```

### 1.1.6.1 Spline Progression

#### Mede:

```text
                    - distância real na pista
                    - direção válida
                    - avanço legítimo
```

#### NÃO usar:

```text
                    - apenas checkpoint count
```

### 1.1.6.2 Checkpoint Validation

#### Responsável por:

```text
                    - validação sequencial
                    - checkpoint ordering
                    - fail states
                    - anti-skip
```

### 1.1.6.3 Shortcut Validation

#### Responsável por:

```text
                    - permitir atalhos legítimos
                    - bloquear exploits
                    - validar áreas opcionais
```

### 1.1.6.4 Anti-Cheat Logic

#### Detecta:

```text
                    - teleporte
                    - reversão ilegal
                    - skip de progresso
                    - velocidade impossível
```

---


### 1.1.7 Integrations

#### Responsável por:

```text
                - desacoplamento entre sistemas
                - comunicação indireta
                - adapters de runtime
```

### 1.1.7.1 Traffic Adapter

#### Responsável por:

```text
                    - sincronizar corrida/tráfego
                    - controlar densidade
                    - evitar caos excessivo
```

### 1.1.7.2 Police Adapter

#### Responsável por:

```text
                    - solicitar perseguições
                    - solicitar roadblocks
                    - injetar pressão policial
                    - sincronizar heat
```

### 1.1.7.3 Economy Adapter

#### Responsável por:

```text
                    - payout
                    - apostas
                    - reward scaling
                    - multas/danos
```

### 1.1.7.4 Mission Adapter

#### Responsável por:

```text
                    - objetivos especiais
                    - eventos dinâmicos
                    - missões híbridas
```

---


### 1.1.8 Rewards

#### Responsável por:

```text
                - progressão financeira
                - reputação
                - desbloqueios
                - scaling de recompensa
```

### 1.1.8.1 Cash Rewards

#### Baseado em:

```text
                    - posição
                    - dificuldade
                    - heat
                    - clean racing
                    - style
```

### 1.1.8.2 Reputation Rewards

#### Mede:

```text
                    - notoriedade
                    - estilo
                    - domínio territorial
                    - vitórias importantes
```

### 1.1.8.3 Crew Reputation

#### Responsável por:

```text
                    - reputação coletiva
                    - influência da crew
                    - rivalidades
```

### 1.1.8.4 Unlock System

#### Responsável por:

```text
                    - carros
                    - peças
                    - eventos
                    - sponsors
                    - áreas da cidade
```

---

### 1.1.9 Telemetry

#### Responsável por:

```text
                - analytics
                - balancing
                - tuning de IA
                - métricas de gameplay
```

### 1.1.9.1 Heatmaps

#### Mede:

```text
                    - crashes
                    - atalhos
                    - zonas difíceis
                    - tráfego problemático
```

### 1.1.9.2 Difficulty Metrics

#### Mede:

```text
                    - win rate
                    - retry rate
                    - abandono
                    - dificuldade percebida
```

### 1.1.9.3 Crash Analytics

#### Mede:

```text
                    - frequência
                    - intensidade
                    - causas
                    - zonas críticas
```

### 1.1.9.4 AI Performance

#### Mede:

```text
                    - eficiência
                    - agressividade
                    - ultrapassagens
                    - rubber banding effectiveness
```

---

### 1.1.10 Online

#### Responsável por:

```text
                - sincronização online
                - sessões multiplayer
                - replicação
                - ghosts
                - matchmaking runtime
```

### 1.1.10.1 Synchronization

#### Responsável por:

```text
                    - sincronização de estado
                    - latency compensation
                    - prediction
                    - reconciliation
```

### 1.1.10.2 Ghost System

#### Responsável por:

```text
                    - replay competitivo
                    - time attack ghosts
                    - records assíncronos
```

### 1.1.10.3 Match Runtime

#### Responsável por:

```text
                    - lifecycle multiplayer
                    - lobby states
                    - matchmaking flow
```

### 1.1.10.4 Replication

#### Responsável por:

```text
                    - replicação de veículos
                    - replicação de polícia
                    - replicação de eventos
                    - state authority
```

</details>

---

<details>
<summary><strong>1.2 Police Systems</strong></summary>

---

## Overview

```text
        Responsável por:
            - perseguições
            - escalada de tensão
            - pressão psicológica
            - resposta dinâmica do mundo
            - pacing emergente

        A polícia NÃO deve:
            - dirigir realisticamente
            - depender de física perfeita
            - agir como simulador policial

        Objetivo:
            - criar perseguições cinematográficas
            - manter pressão constante
            - gerar momentos memoráveis
```

---

### 1.2.1 Director

>Esse é o cérebro estratégico da polícia.

#### Responsável por:

```text
                - intensidade da perseguição
                - controle de pressão
                - escalada de unidades
                - coordenação global
                - pacing da perseguição
```

#### Controla:

```text
                - quantidade de unidades
                - agressividade
                - frequência de roadblocks
                - helicópteros
                - cooldowns
```

---

### 1.2.2 Pursuit Runtime

#### Responsável por:

```text
                - sessão ativa de perseguição
                - lifecycle da pursuit
                - estado do jogador
                - timers
                - coordenação operacional
```

#### Estados:

```text
                - DETECTED
                - PURSUIT
                - ESCALATED
                - SEARCH
                - COOLDOWN
                - ESCAPED
```

#### NÃO deve:

```text
                - controlar spawning diretamente
                - controlar IA individual
```

---

### 1.2.3 Tactical AI

#### Responsável por:

```text
                - bloqueios
                - PIT maneuvers
                - interceptação
                - pressão lateral
                - coordenação entre viaturas
```

#### IA deve:

```text
                - trapacear discretamente
                - priorizar diversão
                - parecer inteligente
```

#### NÃO deve:

```text
                - seguir física perfeita
                - depender de pathfinding puro
```

---

### 1.2.4 Heat System

#### Responsável por:

```text
                - notoriedade
                - agressividade policial
                - escala operacional
```

#### Mede:

```text
                - infrações
                - duração da perseguição
                - destruição
                - velocidade
                - evasões anteriores
```

#### Heat influencia:

```text
                - tipos de viatura
                - IA
                - frequência de backup
                - táticas
```

---

### 1.2.5 Spawn System

#### Responsável por:

```text
                - spawn policial
                - entradas dinâmicas
                - reforços
```

#### Spawn deve:

```text
                - ocorrer fora de visão
                - respeitar streaming
                - respeitar pacing
```

#### NÃO deve:

```text
                - spawnar em frente ao jogador
                - quebrar imersão
```

---

### 1.2.6 Search System

#### Responsável por:

```text
                - busca do jogador
                - zonas de procura
                - última posição conhecida
                - cooldown de perseguição
```

#### Sistema deve:

```text
                - criar tensão
                - permitir escape dramático
                - evitar onisciência policial
```

---

### 1.2.7 Roadblock System

#### Responsável por:

```text
                - roadblocks
                - spike strips
                - barreiras móveis
```

#### Roadblocks devem:

```text
                - parecer coordenados
                - aumentar pressão
                - variar localização
```

#### NÃO devem:

```text
                - ser impossíveis
                - parecer injustos
```

---

### 1.2.8 Helicopter System

#### Responsável por:

```text
                - suporte aéreo
                - iluminação
                - tracking psicológico
```

#### Helicóptero NÃO precisa:

```text
                - física realista
                - simulação aeronáutica
```

#### Objetivo:

```text
                - pressão psicológica
                - sensação cinematográfica
```

---

### 1.2.9 Escalation System

#### Responsável por:

```text
                - progressão de dificuldade
                - mudança de unidades
                - resposta crescente
```

#### Escala:

```text
                Patrol
                ↓
                Interceptors
                ↓
                SUVs
                ↓
                Heavy Units
                ↓
                Federal Response
```

---

### 1.2.10 Radio System

#### Responsável por:

```text
                - chatter policial
                - coordenação
                - informação contextual
```

#### Rádio deve:

```text
                - aumentar imersão
                - comunicar escalada
                - informar ações policiais
```

---

### 1.2.11 Vehicle Enforcement

#### Responsável por:

```text
                - dano policial
                - pressão física
                - impacto operacional
```

#### Mede:

```text
                - dano acumulado
                - colisões
                - eficiência de PIT
```

---

### 1.2.12 Jurisdiction System

#### Responsável por:

```text
                - divisão territorial
                - níveis de resposta
                - comportamento regional
```

#### Regiões podem alterar:

```text
                - agressividade
                - frequência policial
                - tipos de unidade
```

---

### 1.2.13 World Response

#### Responsável por:

```text
                - resposta dinâmica da cidade
                - reação do tráfego
                - alteração ambiental
```

#### Pode controlar:

```text
                - fechamento de vias
                - trânsito alterado
                - eventos emergentes
                - suporte policial indireto
```

</details>

---

<details>
<summary><strong>1.3 Carrer Systems</strong></summary>

---

## Overview

```text
        Responsável por:
            - progressão do jogador
            - narrativa estrutural
            - reputação
            - desbloqueios
            - rivalidades
```

---

### 1.3.1 Blacklist

>Inspirado em:Blacklist do most wanted

#### Responsável por:

```text
                - rivais principais
                - progressão hierárquica
                - bosses
                - milestones
```

---

### 1.3.2 Crew Progression

#### Responsável por:

```text
                - evolução da crew
                - desbloqueios coletivos
                - influência territorial
```

---

### 1.3.3 Reputation

#### Mede:

```text
                - estilo
                - notoriedade
                - domínio
                - agressividade
                - fama
```

---

### 1.3.4 Story Events

#### Responsável por:

```text
                - narrativa
                - eventos cinematográficos
                - rivalidades
                - introduções
```

---

### 1.3.5 Unlock Progression

#### Controla:

```text
                - carros
                - peças
                - eventos
                - sponsors
                - áreas
```

---

### 1.3.6 Event Availability

#### Responsável por:

```text
                - rotação de eventos
                - gating de progressão
                - dificuldade regional
```

</details>

---

<details>
<summary><strong>1.4 Economy Systems</strong></summary>

---

## Overview

```text
        Responsável por:
            - economia global
            - progressão financeira
            - scaling
            - risco/recompensa
```

---

### 1.4.1 Currency

#### Controla:

```text
                - dinheiro
                - ganhos
                - perdas
                - multas
```

---

### 1.4.2 Reward Scaling

#### Ajusta:

```text
                - payout
                - dificuldade
                - heat
                - risco
```

---

### 1.4.3 Car Pricing

#### Responsável por:

```text
                - valor de veículos
                - raridade
                - mercado
```

---

### 1.4.4 Upgrade Pricing

#### Responsável por:

```text
                - tuning economy
                - balancing
                - progressão técnica
```

---

### 1.4.5 Sponsorships

#### Responsável por:

```text
                - contratos
                - desafios
                - bônus especiais
```

---

### 1.4.6 Risk/Reward Logic

#### Mede:

```text
                - heat alto
                - perseguições
                - apostas
                - eventos perigosos
```

</details>

---

<details>
<summary><strong>1.5 Mission Systems</strong></summary>

---

## Overview

```text
        Responsável por:
            - objetivos
            - scripting de eventos
            - narrativa dinâmica
            - eventos cinematográficos
            - integração contextual com o mundo

        NÃO deve:
            - controlar física
            - controlar rendering
            - possuir lógica hardcoded de corrida
```

---

### 1.5.1 Objective Runtime

#### Responsável por:

```text
                - objetivos ativos
                - validação de missão
                - fail states
                - progressão dinâmica
```

#### Tipos:

```text
                - Reach Target
                - Escape Police
                - Win Race
                - Deliver Vehicle
                - Survive Timer
```

---

### 1.5.2 Trigger System

#### Responsável por:

```text
                - ativação contextual
                - trigger volumes
                - eventos regionais
                - transições
```

#### Pode ativar:

```text
                - perseguições
                - cutscenes
                - emboscadas
                - chamadas de rádio
```

---

### 1.5.3 Dynamic Events

#### Responsável por:

```text
                - eventos emergentes
                - encontros aleatórios
                - desafios contextuais
```

#### Exemplos:

```text
                - rival encontra jogador
                - polícia reforça região
                - corrida espontânea
                - emboscada de crew
```

---

### 1.5.4 Script Runtime

#### Responsável por:

```text
                - execução de scripts
                - controle narrativo
                - lógica sequencial
```

#### NÃO deve:

```text
                - possuir lógica de baixo nível
                - acessar sistemas diretamente
```

#### Deve usar:

```text
                - adapters
                - event bus
                - gameplay hooks
```

---

### 1.5.5 World Events

#### Responsável por:

```text
                - eventos globais
                - alterações de mundo
                - pacing urbano
```

#### Exemplos:

```text
                - chuva forte
                - lockdown policial
                - blackout
                - congestionamento
```

---

### 1.5.6 Cinematic Hooks

#### Responsável por:

```text
                - integração com cinematics
                - transições
                - câmera contextual
                - eventos dramáticos
```

</details>

---

<details>
<summary><strong>1.6 World Systems</strong></summary>

---

## Overview

```text
        Responsável por:
            - comportamento urbano
            - ambientação
            - simulação contextual
            - dinâmica do mundo aberto
```

---

### 1.6.1 Traffic Runtime

#### Responsável por:

```text
                - veículos civis
                - densidade urbana
                - comportamento de tráfego
```

#### Tráfego deve:

```text
                - parecer vivo
                - favorecer gameplay
                - criar momentos emergentes
```

#### NÃO deve:

```text
                - simular trânsito realista extremo
```

---

### 1.6.2 Civilian AI

#### Responsável por:

```text
                - comportamento civil
                - reação ao caos
                - evasão
                - resposta contextual
```

---

### 1.6.3 Pedestrian Logic

#### Responsável por:

```text
                - densidade populacional
                - reações ambientais
                - ambientação urbana
```

#### Objetivo:

>aumentar sensação de cidade viva

---

### 1.6.4 Ambient Events

#### Responsável por:

```text
                - pequenas ocorrências urbanas
                - sensação de atividade
```

#### Exemplos:

```text
                - acidentes leves
                - caminhões parados
                - obras
                - eventos urbanos
```

---

### 1.6.5 Day/Night Cycle

#### Responsável por:

```text
                - ciclo temporal
                - iluminação contextual
                - alteração atmosférica
```

#### Deve influenciar:

```text
                - polícia
                - tráfego
                - eventos
                - atmosfera
```

---

### 1.6.6 Weather Runtime

#### Responsável por:

```text
                - chuva
                - neblina
                - tempestades
                - umidade
```

#### Deve influenciar:

```text
                - dirigibilidade
                - visibilidade
                - cinematografia
```

---

### 1.6.7 World Director

>Esse é o cérebro do mundo aberto.

#### Responsável por:

```text
                - intensidade urbana
                - atividade contextual
                - equilíbrio entre caos e calmaria
```

#### Controla:

```text
                - tráfego
                - polícia regional
                - ambientação
                - eventos emergentes
```

</details>

---

<details>
<summary><strong>1.7 Global Director</strong></summary>

---

## Overview

```text
        Responsável por:
            - orchestration global
            - pacing macro
            - coordenação sistêmica

        É:
            - camada estratégica global
            - autoridade de intensidade
            - controlador de ritmo do jogo

        NÃO deve:
            - dirigir veículos
            - controlar física
            - controlar entidades individualmente
```

---

### 1.7.1 World Pacing

#### Responsável por:

```text
                - alternância de intensidade
                - descanso emocional
                - escalada de tensão
```

#### Objetivo:

```text
                - evitar fadiga constante
                - manter flow cinematográfico
```

### 1.7.2 Dynamic Intensity

#### Mede:

```text
                - performance do jogador
                - caos atual
                - nível de pressão
                - risco percebido
```

#### Ajusta:

```text
                - agressividade
                - spawn rates
                - frequência de eventos
```

### 1.7.3 Traffic Density

#### Responsável por:

```text
                - densidade global
                - distribuição urbana
                - pacing de tráfego
```

### 1.7.4 Police Pressure

#### Responsável por:

```text
                - pressão policial macro
                - saturação de perseguições
                - heat regional
```

### 1.7.5 Audio Intensity

#### Responsável por:

```text
                - intensidade musical
                - layering de soundtrack
                - transições sonoras
```

#### Deve responder:

```text
                - velocidade
                - perseguição
                - tensão
                - risco
```

### 1.7.6 Event Orchestration

#### Responsável por:

```text
                - sincronização de grandes eventos
                - pacing cinematográfico
                - controle de espetáculo
```

#### Exemplos:

```text
                - blackout durante pursuit
                - tempestade iniciando em corrida
                - lockdown policial
                - entrada de rival crew
```

</details>

---

</details>

---

<details>
<summary><strong>🧠 Simulation Layer</strong></summary>

```text
2. Simulation Layer
├── Vehicle Simulation
│   ├── Tire Model
│   ├── Suspension
│   ├── Differential
│   ├── Weight Transfer
│   ├── Drift Assist
│   ├── Stability Assist
│   ├── Traction Assist
│   ├── Aero Simulation
│   ├── Surface Response
│   ├── Collision Solver
│   └── Damage Simulation
│
├── Traffic Simulation
│   ├── Lane System
│   ├── Traffic Behaviors
│   ├── Avoidance System
│   ├── Density Solver
│   └── Intersection Logic
│
├── AI Simulation
│   ├── Navigation Runtime
│   ├── Pathfinding
│   ├── Utility AI
│   ├── Behavior Trees
│   └── Decision Scheduler
│
├── World Streaming
│   ├── District Streaming
│   ├── LOD Manager
│   ├── Async Loading
│   ├── Occlusion System
│   ├── Asset Streaming
│   └── Memory Budgeting
│
└── Physics Runtime
    ├── Broadphase
    ├── Narrowphase
    ├── Constraint Solver
    ├── Raycasts
    └── Collision Queries
```
### Responsibilities

- Vehicle physics
- AI processing
- Streaming
- Traffic behavior
- Collision runtime

# 2. Simulation Layer

>Onde a simulaçao é orquestrada.

---

## Responsável por:

```text
        - simulação física
        - comportamento matemático
        - runtime de IA
        - movimentação
        - colisões
        - navegação
        - streaming operacional
```

---

## NÃO deve:

```text
        - conter regras de gameplay
        - controlar progressão
        - controlar narrativa
        - controlar pacing cinematográfico
```

---

## Objetivo:

```text
        - fornecer simulação consistente
        - manter previsibilidade sistêmica
        - sustentar gameplay emergente
```

---

<details>
<summary><strong>2.1 Vehicle Simulation</strong></summary>

---

## Overview

```text
        Responsável por:
            - comportamento dos veículos
            - física automotiva
            - resposta de dirigibilidade
            - sensação de controle

        Objetivo:
            - simcade cinematográfico
            - sensação agressiva
            - controle responsivo

        NÃO deve:
            - ser simulador extremo
            - sacrificar diversão por realismo
```

---

### 2.1.1 Tire Model

#### Responsável por:

```text
                - aderência
                - perda de tração
                - slip angles
                - comportamento lateral
```

#### Deve controlar:

```text
                - grip progressivo
                - breakaway previsível
                - recuperação controlável
```

### 2.1.2 Suspension

#### Responsável por:

```text
                - absorção de impacto
                - transferência de peso
                - estabilidade
```

#### Deve influenciar:

```text
                - drift
                - curvas
                - sensação de velocidade
```

### 2.1.3 Differential

#### Responsável por:

```text
                - distribuição de torque
                - comportamento em aceleração
                - estabilidade de saída de curva
```

### 2.1.4 Weight Transfer


#### Responsável por:

```text
                - movimentação dinâmica de massa
                - sensação de peso
                - estabilidade
```

#### Deve:

```text
                - parecer real
                - permanecer arcade
```

### 2.1.5 Drift Assist

#### Responsável por:

```text
                - estabilidade de drift
                - transições
                - countersteering assist
```

#### NÃO deve:

```text
                - dirigir pelo jogador
                - parecer automático
```

### 2.1.6 Stability Assist

#### Responsável por:

```text
                - recuperação de controle
                - estabilidade em alta velocidade
                - suavização de inputs
```

### 2.1.7 Traction Assist

#### Responsável por:

```text
                - controle de wheelspin
                - saída de curva
                - launches
```

### 2.1.8 Aero Simulation

#### Responsável por:

```text
                - downforce
                - drag aerodinâmico
                - estabilidade em alta velocidade
```

### 2.1.9 Surface Response

#### Responsável por:
>resposta do veículo ao terreno

```text
            Superfícies:
                - asfalto
                - concreto
                - terra
                - água
                - óleo
                - grama
```

### 2.1.10 Collision Solver

#### Responsável por:

```text
                - impactos
                - transferência de força
                - deformações simplificadas
```

#### Objetivo:

```text
                - impacto cinematográfico
                - feedback visual forte
```

### 2.1.11 Damage Simulation

#### Responsável por:

```text
                - dano mecânico
                - dano visual
                - degradação operacional
```

#### Pode afetar:

```text
                - velocidade
                - steering
                - aceleração
                - estabilidade
```

</details>

---

<details>
<summary><strong>2.2 Traffic Simulation</strong></summary>

---

## Overview

```text
        Responsável por:
            - veículos civis
            - fluxo urbano
            - comportamento ambiental
```

---

### 2.2.1 Lane System

#### Responsável por:

```text
                - lanes
                - fluxo de trânsito
                - organização viária
```

### 2.2.2 Traffic Behaviors

#### Responsável por:

```text
                - aceleração
                - frenagem
                - trocas de faixa
                - reação ao jogador
```

### 2.2.3 Avoidance System

#### Responsável por:

```text
                - evasão de colisões
                - prevenção de deadlocks
                - resposta emergencial
```

### 2.2.4 Density Solver

#### Responsável por:

```text
                - densidade de veículos
                - distribuição dinâmica
                - controle de carga computacional
```

### 2.2.5 Intersection Logic

#### Responsável por:

```text
                - cruzamentos
                - prioridade
                - semáforos
                - bloqueios
```

</details>

---

<details>
<summary><strong>2.3 AI Simulation</strong></summary>

---

## Overview

```text
        Responsável por:
            - tomada de decisão
            - navegação
            - comportamento contextual
            - processamento de IA
```

### 2.3.1 Navigation Runtime

#### Responsável por:

```text
                - navegação em mundo aberto
                - rotas
                - atualização dinâmica
```

### 2.3.2 Pathfinding

#### Responsável por:

```text
                - cálculo de caminhos
                - rotas alternativas
                - desvios contextuais
```

#### NÃO deve:

```text
                - recalcular tudo constantemente
```

### 2.3.3 Utility AI

#### Responsável por:

```text
                - decisões contextuais
                - avaliação de utilidade
                - prioridades dinâmicas
```

#### Melhor para:

```text
                - racers
                - polícia
                - crews
```

### 2.3.4 Behavior Trees

#### Responsável por:

```text
                - comportamento procedural
                - execução hierárquica
                - sequências táticas
```

### 2.3.5 Decision Scheduler

#### Responsável por:

```text
                - distribuição de processamento
                - frequência de atualização
                - otimização de IA
```

#### Objetivo:

>evitar gargalos CPU

</details>

---

<details>
<summary><strong>2.4 World Streaming</strong></summary>

---

## Overview

```text
        Responsável por:
            - carregamento do mundo
            - descarregamento
            - memória
            - streaming assíncrono

        Objetivo:
            - eliminar loading perceptível
            - manter performance estável
```

---

### 2.4.1 District Streaming

#### Responsável por:

```text
                - carregamento regional
                - transição de distritos
```

### 2.4.2 LOD Manager

#### Responsável por:

```text
                - level of detail
                - redução de custo gráfico
                - troca dinâmica de assets
```

### 2.4.3 Async Loading

#### Responsável por:

```text
                - carregamento assíncrono
                - preloading
                - streaming preditivo
```

### 2.4.4 Occlusion System

#### Responsável por:

```text
                - ocultação
                - redução de draw calls
                - economia de GPU
```

### 2.4.5 Asset Streaming

#### Responsável por:

```text
                - texturas
                - meshes
                - áudio
                - efeitos
```

### 2.4.6 Memory Budgeting

#### Responsável por:

```text
                - limite de memória
                - descarregamento inteligente
                - prevenção de overflow
```

</details>

---

<details>
<summary><strong>2.5 Physics Runtime</strong></summary>

---

## Overview

```text
        Responsável por:
            - física global
            - colisões
            - queries físicas
            - constraints
```

### 2.5.1 Broadphase

#### Responsável por:

```text
                - filtragem inicial de colisões
                - redução de custo computacional
```

### 2.5.2 Narrowphase

#### Responsável por:

```text
                - resolução precisa de colisões
                - contatos detalhados
```

### 2.5.3 Constraint Solver

#### Responsável por:

```text
                - juntas
                - suspensão
                - conexões físicas
```

### 2.5.4 Raycasts

#### Responsável por:

```text
                - detecção de superfície
                - sensores
                - IA 
                - suspensão
```

### 2.5.5 Collision Queries

#### Responsável por:

```text
                - overlap tests
                - sweep tests
                - spatial queries
```

</details>

---

</details>

---

<details>
<summary><strong>⚙️ Core Layer</strong></summary>

```text
1. Core Layer
├── ECS Runtime
│   ├── Entities
│   ├── Components
│   ├── Systems
│   └── Archetypes
│
├── Event Bus
│   ├── Global Events
│   ├── Local Events
│   ├── Async Queue
│   └── Event Priorities
│
├── State Machine Framework
│   ├── Global States
│   ├── Local States
│   └── Transition Rules
│
├── Task Scheduler
│   ├── Job Distribution
│   ├── Priority Scheduling
│   └── Runtime Budgeting
│
├── Async Job System
│   ├── Background Jobs
│   └── Thread Pools
│
├── Save System
│   ├── Player Save
│   ├── World Save
│   ├── Serialization
│   └── Versioning
│
├── Replay Runtime
│   ├── Input Recording
│   ├── State Recording
│   ├── Playback Runtime
│   └── Replay Cameras
│
├── Replication Layer
│   ├── State Replication
│   ├── Prediction
│   ├── Reconciliation
│   └── Network Priority
│
├── Resource Manager
│   ├── Asset References
│   ├── Runtime Cache
│   └── Memory Tracking
│
├── Asset Registry
│   ├── Vehicle Assets
│   ├── World Assets
│   └── Audio Assets
│
├── Data Serialization
│   ├── Binary Serialization
│   └── Config Serialization
│
├── Config Runtime
│   ├── Gameplay Configs
│   ├── AI Configs
│   └── Economy Configs
│
├── Debug/Profiling Tools
│   ├── Performance Metrics
│   ├── AI Debug
│   ├── Physics Debug
│   └── Streaming Debug
│
└── Memory Manager
    ├── Pool Allocators
    ├── Streaming Memory
    └── Leak Detection
```
### Responsibilities

- ECS
- Scheduling
- Replication
- Save system
- Memory
- Resource management

# 3. Core Layer

>Nucleo e infraestura ligada ao jogo.

## Responsável por:

```text
        - infraestrutura central
        - comunicação sistêmica
        - gerenciamento de runtime
        - persistência
        - execução assíncrona
        - authority global
```

---

## Objetivo:

```text
        - sustentar todos os layers
        - evitar acoplamento direto
        - garantir escalabilidade
        - garantir estabilidade operacional
```

---

## NÃO deve:

```text
        - conter gameplay
        - conter regras de corrida
        - conter narrativa
        - conter lógica visual
```

---

<details>
<summary><strong>3.1 ECS Runtime</strong></summary>

---

## Overview

```text
        Responsável por:
            - gerenciamento de entidades
            - components
            - systems
            - processamento massivo

        Objetivo:
            - escalabilidade
            - paralelismo
            - performance
```

---


### 3.1.1 Entities

#### Representam:

```text
                - carros
                - polícia
                - tráfego
                - objetos
                - triggers
```

### 3.1.2 Components

#### Contêm:

```text
                - dados puros
                - estado
                - configuração
```

### NÃO devem:
>possuir lógica pesada

### 3.1.3 Systems

#### Responsáveis por:

```text
                - processamento
                - execução paralela
                - atualização de entidades
```

### 3.1.4 Archetypes

#### Responsáveis por:

```text
                - agrupamento eficiente
                - cache locality
                - performance massiva
```

</details>

---

<details>
<summary><strong>3.2 Event Bus</strong></summary>

---

## Overview

```text
        Responsável por:
            - comunicação desacoplada
            - propagação de eventos
            - integração sistêmica

        Objetivo:
            - evitar dependência direta
            - facilitar replay
            - facilitar telemetry
            - facilitar online
```

---

### 3.2.1 Global Events

#### Exemplos:

```text
                - OnRaceStart
                - OnPursuitBegin
                - OnPlayerCrash
                - OnDistrictLoaded
```

### 3.2.2 Local Events

#### Responsáveis por:

```text
                - eventos regionais
                - eventos temporários
                - comunicação contextual
```

### 3.2.3 Async Queue

#### Responsável por:

```text
                - processamento assíncrono
                - buffering
                - ordenação
```

### 3.2.4 Event Priorities

#### Prioridades:

```text
                - Critical
                - High
                - Normal
                - Background
```

</details>

---

<details>
<summary><strong>3.3 State Machine Framework</strong></summary>

---

## Overview

```text
        Responsável por:
            - controle de estados
            - transições
            - validação de runtime

        Objetivo:
            - previsibilidade
            - estabilidade
            - prevenção de estados inválidos
```

---

### 3.3.1 Global States

#### Exemplos:

```text
                - MainMenu
                - FreeRoam
                - Race
                - Pursuit
                - Garage
```

### 3.3.2 Local States

#### Exemplos:

```text
                - Countdown
                - DriftChain
                - SearchMode
```

### 3.3.3 Transition Rules

#### Responsável por:

```text
                - validar transições
                - impedir estados ilegais
```

</details>

---

<details>
<summary><strong>3.4 Task Scheduler</strong></summary>

---

## Overview

```text
        Responsável por:
            - distribuição de tarefas
            - balanceamento de carga
            - atualização de sistemas

        Objetivo:
            - evitar gargalos
            - otimizar CPU
            - escalabilidade multicore
```

### 3.4.1 Job Distribution

#### Responsável por:

```text
                - distribuição paralela
                - worker threads
```

### 3.4.2 Priority Scheduling

#### Prioridades:

```text
                - gameplay crítico
                - física
                - IA
                - background
```

### 3.4.3 Runtime Budgeting

#### Responsável por:

```text
                - limitar custo de frame
                - controlar overload
```

</details>

---

<details>
<summary><strong>3.5 Async Job System</strong></summary>

---

## Overview

```text
        Responsável por:
            - tarefas assíncronas
            - IO
            - streaming
            - cálculos pesados
```

### 3.5.1 Background Jobs

#### Exemplos:

```text
                - loading
                - compressão
                - analytics
```

### 3.5.2 Thread Pools

#### Responsável por:

```text
                - reutilização de threads
                - otimização de CPU
```

</details>

---

<details>
<summary><strong>3.6 Save System</strong></summary>

---

## Overview

```text
        Responsável por:
            - persistência
            - serialização
            - carregamento

        Objetivo:
            - salvar estado global
            - suportar mundo persistente
```

---

### 3.6.1 Player Save

#### Contém:

```text
                - progressão
                - carros
                - dinheiro
                - reputação
```

### 3.6.2 World Save

#### Contém:

```text
                - estado do mundo
                - eventos ativos
                - mudanças persistentes
```

### 3.6.3 Serialization

#### Responsável por:

```text
                - compactação
                - escrita eficiente
                - leitura segura
```

### 3.6.4 Versioning

#### Responsável por:

```text
                - compatibilidade
                - migração de save
                - patches futuros
```

</details>

---

<details>
<summary><strong>3.7 Replay Runtime</strong></summary>

---

## Overview

```text
        Responsável por:
            - gravação temporal
            - playback
            - replay cinematográfico
```

### 3.7.1 Input Recording

#### Responsável por:

```text
                - inputs do jogador
                - sincronização temporal
```

### 3.7.2 State Recording

#### Responsável por:

```text
                - transforms
                - velocidade
                - eventos importantes
```

### 3.7.3 Playback Runtime

#### Responsável por:

```text
                - reprodução
                - sincronização
                - timeline
```

### 3.7.4 Replay Cameras

#### Responsável por:

```text
                - câmeras cinematográficas
                - cortes dinâmicos
                - tracking
```

</details>

---

<details>
<summary><strong>3.8 Replication Layer</strong></summary>

---

## Overview

```text
        Responsável por:
            - sincronização online
            - authority
            - estado de rede
```

### 3.8.1 State Replication

#### Responsável por:

```text
                - replicar entidades
                - replicar estados críticos
```

### 3.8.2 Prediction

#### Responsável por:

```text
                - client prediction
                - suavização
```

### 3.8.3 Reconciliation

#### Responsável por:

```text
                - correção de desync
                - validação de authority
```

### 3.8.4 Network Priority

#### Prioriza:

```text
                - player
                - polícia próxima
                - racers próximos
```

</details>

---

<details>
<summary><strong>3.9 Resource Manager</strong></summary>

---

## Overview

```text
        Responsável por:
            - gerenciamento de assets
            - memória
            - cache

        Objetivo:
            - evitar duplicação
            - otimizar carregamento
```

---

### 3.9.1 Asset References

#### Responsável por:

```text
                - referências seguras
                - controle de uso
```

### 3.9.2 Runtime Cache

#### Responsável por:

```text
                - cache inteligente
                - reutilização
```

### 3.9.3 Memory Tracking

#### Responsável por:

```text
                - monitoramento de memória
                - prevenção de leaks
```

</details>

---

<details>
<summary><strong>3.10 Asset Registry</strong></summary>

---

## Overview

```text
        Responsável por:
            - catalogar assets
            - lookup
            - metadata
```

### 3.10.1 Vehicle Assets

#### Contém:

```text
                - carros
                - peças
                - tuning
```

### 3.10.2 World Assets

#### Contém:

```text
                - distritos
                - props
                - tráfego
```

### 3.10.3 Audio Assets

#### Contém:

```text
                - música
                - rádio
                - FX
```

</details>

---

<details>
<summary><strong>3.11 Data Serialization</strong></summary>

---

## Overview

```text
        Responsável por:
            - conversão de dados
            - persistência binária
            - compactação
```

### 3.11.1 Binary Serialization

#### Objetivo:

```text
                - performance
                - baixo custo
```

### 3.11.2 Config Serialization

#### Responsável por:

```text
                - configs
                - tuning
                - balancing
```

</details>

---

<details>
<summary><strong>3.12 Config Runtime</strong></summary>

---

## Overview

```text
        Responsável por:
            - configuração dinâmica
            - balancing
            - tuning em runtime
```

### 3.12.1 Gameplay Configs

#### Controla:

```text
                - drift assist
                - heat
                - rewards
```

### 3.12.2 AI Configs

#### Controla:

```text
                - agressividade
                - reaction times
                - pursuit pressure
```

### 3.12.3 Economy Configs

#### Controla:

```text
                - preços
                - scaling
                - payouts
```

</details>

---

<details>
<summary><strong>3.13 Debug/Profiling Tools</strong></summary>

---

## Overview

```text
        Responsável por:
            - debugging
            - profiling
            - análise de performance
```

### 3.13.1 Performance Metrics

#### Mede:

```text
                - frametime
                - CPU
                - GPU
                - streaming cost
```

### 3.13.2 AI Debug

#### Mostra:

```text
                - decisões
                - pathfinding
                - targeting
```

### 3.13.3 Physics Debug

#### Mostra:

```text
                - colisões
                - suspensão
                - raycasts
```

### 3.13.4 Streaming Debug

#### Mostra:

```text
                - carregamento
                - memória
                - LOD transitions
```
</details>

---

<details>
<summary><strong>3.14 Memory Manager</strong></summary>

---

## Overview

```text
        Responsável por:
            - alocação
            - pools
            - fragmentação

        Objetivo:
            - estabilidade
            - previsibilidade
            - baixo overhead
```

### 3.14.1 Pool Allocators

#### Responsável por:

```text
                - allocations rápidas
                - reutilização
```

### 3.14.2 Streaming Memory

#### Responsável por:

```text
                - budget de streaming
                - descarregamento
```

### 3.14.3 Leak Detection

#### Responsável por:

```text
                - detectar vazamentos
                - rastrear referências
```

</details>

---

</details>

---

<details>
<summary><strong>🎨 Presentation Layer</strong></summary>

```text
4. Presentation Layer
├── Rendering
│   ├── Lighting System
│   ├── Post Processing
│   ├── Material System
│   ├── Reflection System
│   ├── Shadow System
│   └── Environment Rendering
│
├── Camera Systems
│   ├── Gameplay Camera
│   ├── Drift Camera
│   ├── Pursuit Camera
│   ├── Crash Camera
│   ├── Replay Camera
│   └── Photo Mode Camera
│
├── UI/HUD
│   ├── Race HUD
│   ├── Pursuit HUD
│   ├── Drift HUD
│   ├── Navigation HUD
│   ├── Online HUD
│   └── Garage UI
│
├── VFX
│   ├── Nitro Effects
│   ├── Drift Effects
│   ├── Weather Effects
│   ├── Damage Effects
│   └── Environmental FX
│
├── Audio Runtime
│   ├── Engine Audio
│   ├── Pursuit Audio
│   ├── Impact Audio
│   ├── Environment Audio
│   └── Spatial Audio
│
├── Music Director
│   ├── Dynamic Layers
│   ├── Pursuit Music
│   ├── Race Music
│   └── Ambient Music
│
├── Cinematics
│   ├── Intro Sequences
│   ├── Rival Introductions
│   ├── Transition Cinematics
│   └── Victory Sequences
│
├── Photo Mode
│   ├── Filters
│   ├── DOF Controls
│   └── Pose Controls
│
└── Accessibility
    ├── Color Accessibility
    ├── Subtitle System
    └── Input Accessibility
```
### Responsibilities

- Rendering
- Cinematics
- Audio
- UI
- Camera behavior
- Visual feedback

# 4. Presentation Layer

>Responsavel pela renderização do conteúdo do jogo.

## Responsável por:

```text
        - apresentação visual
        - feedback audiovisual
        - cinematografia
        - HUD
        - câmera
        - efeitos
        - sensação de impacto
```

---

## Objetivo:

```text
        - transformar simulação em espetáculo
        - aumentar percepção de velocidade
        - reforçar identidade visual
        - elevar intensidade emocional
```

---

## NÃO deve:

```text
        - conter regras de gameplay
        - conter física
        - conter lógica de progressão
        - controlar authority sistêmica
```

---

<details>
<summary><strong>4.1 Rendering</strong></summary>

---

## Overview

```text
        Responsável por:
            - renderização visual
            - iluminação
            - pós-processamento
            - materiais
            - shaders

        Objetivo:
            - alta percepção de velocidade
            - forte identidade visual
            - leitura clara em alta velocidade
```

### 4.1.1 Lighting System

#### Responsável por:

```text
                - iluminação global
                - iluminação dinâmica
                - headlights
                - neon
                - emissive lighting
```

### Deve priorizar:

```text
                - atmosfera
                - leitura visual
                - contraste cinematográfico
```

### 4.1.2 Post Processing

#### Responsável por:

```text
                - motion blur
                - bloom
                - chromatic aberration
                - exposure
                - tone mapping
```

#### Objetivo:

```text
                - sensação extrema de velocidade
                - agressividade visual
```

### 4.1.3 Material System

#### Responsável por:

```text
                - paint shaders
                - wet surfaces
                - reflections
                - metallic response
```

### 4.1.4 Reflection System

#### Responsável por:

```text
                - SSR
                - cubemaps
                - reflections dinâmicas
```

#### Importante para:

```text
                - carros
                - chuva
                - cidade noturna
```

### 4.1.5 Shadow System

#### Responsável por:

```text
                - sombras dinâmicas
                - headlights shadows
                - sombras urbanas
```

### 4.1.6 Environment Rendering

#### Responsável por:

```text
                - cidade
                - skyline
                - horizonte
                - atmosfera urbana
```

</details>

---

<details>
<summary><strong>4.2 Camara Systems</strong></summary>

---

## Overview

```text
        Responsável por:
            - framing
            - percepção de velocidade
            - cinematografia
            - feedback contextual
```

### 4.2.1 Gameplay Camera

#### Responsável por:

```text
                - câmera principal
                - estabilidade visual
                - leitura de gameplay
```

#### Deve:

```text
                - transmitir velocidade
                - permanecer legível
```

### 4.2.2 Drift Camera

#### Responsável por:

```text
                - ângulo cinematográfico
                - amplificação visual do drift
                - tracking lateral
```

### 4.2.3 Pursuit Camera

#### Responsável por:

```text
                - sensação de perseguição
                - tensão
                - impacto
```

#### Deve:

```text
                - parecer agressiva
                - aumentar intensidade
```

### 4.2.4 Crash Camera

#### Responsável por:

```text
                - slow motion
                - impacto visual
                - dramaticidade
```

### 4.2.5 Replay Camera

#### Responsável por:

```text
                - câmeras cinematográficas
                - cortes dinâmicos
                - tracking inteligente
```

### 4.2.6 Photo Mode Camera

### Responsável por:

```text
                - câmera livre
                - DOF
                - composição visual
```

</details>

---

<details>
<summary><strong>4.3 UI/HUD</strong></summary>

---

## Overview

```text
        Responsável por:
            - interface
            - feedback ao jogador
            - leitura rápida
            - telemetria visual

        Objetivo:
            - legibilidade extrema
            - baixa distração
            - resposta rápida
```

### 4.3.1 Race HUD

#### Contém:

```text
                - velocidade
                - posição
                - minimap
                - nitro
                - checkpoints
```

### 4.3.2 Pursuit HUD

#### Contém:

```text
                - heat
                - status policial
                - cooldown
                - unidades ativas
```

### 4.3.3 Drift HUD

#### Contém:

```text
                - combo
                - multiplicador
                - ângulo
                - score
```

### 4.3.4 Navigation HUD

#### Responsável por:

```text
                - GPS
                - rotas
                - guidance dinâmica
```

### 4.3.5 Online HUD
            
#### Contém:

```text
                - ping
                - posição online
                - players próximos
```

### 4.3.6 Garage UI
            
#### Responsável por:

```text
                - tuning
                - customização
                - marketplace
```

</details>

---

<details>
<summary><strong>4.4 VFX</strong></summary>

---

## Overview

```text
        Responsável por:
            - partículas
            - fumaça
            - sparks
            - explosões visuais
            - feedback de velocidade
```

### 4.4.1 Nitro Effects

#### Responsável por:

```text
                - flames
                - distortion
                - boost visuals
```

### 4.4.2 Drift Effects

#### Responsável por:

```text
                - fumaça
                - skid marks
                - partículas laterais
```

### 4.4.3 Weather Effects

#### Responsável por:

```text
                - chuva
                - água
                - respingos
                - neblina
```

### 4.4.4 Damage Effects

#### Responsável por:

```text
                - debris
                - sparks
                - peças soltas
```

### 4.4.5 Environmental FX

#### Responsável por:

```text
                - poeira
                - lixo urbano
                - vento
                - folhas
```

</details>

---

<details>
<summary><strong>4.5 Audio Runtime</strong></summary>

---

## Overview

```text
        Responsável por:
            - áudio procedural
            - spatial audio
            - mixagem dinâmica
            - feedback sonoro

        Objetivo:
            - sensação mecânica brutal
            - pressão sonora
            - intensidade emocional
```

### 4.5.1 Engine Audio

#### Responsável por:

```text
                - RPM blending
                - turbo
                - transmission whine
                - intake
                - exhaust
```

### 4.5.2 Pursuit Audio

#### Responsável por:

```text
                - sirenes
                - rádio policial
                - tensão sonora
```

### 4.5.3 Impact Audio

#### Responsável por:

```text
                - colisões
                - metal
                - destruição
```

### 4.5.4 Environment Audio

#### Responsável por:

```text
                - cidade
                - túneis
                - chuva
                - crowd ambience
```

### 4.5.5 Spatial Audio

#### Responsável por:
```text
                - posicionamento 3D
                - doppler
                - distância sonora
```

</details>

---

<details>
<summary><strong>4.6 Music Director</strong></summary>

---

## Overview

```text
        Responsável por:
            - soundtrack dinâmica
            - intensidade musical
            - layering adaptativo

        Objetivo:
            - sincronizar emoção e gameplay
```

### 4.6.1 Dynamic Layers

#### Responsável por:

```text
                - adicionar/remover camadas musicais
                - escalada de intensidade
```

### 4.6.2 Pursuit Music

#### Responsável por:

```text
                - tensão policial
                - escalada sonora
```

### 4.6.3 Race Music

#### Responsável por:

```text
                - intensidade competitiva
                - ritmo
```

### 4.6.4 Ambient Music

#### Responsável por:

```text
                - exploração
                - calmaria
                - atmosfera urbana
```

</details>

---

<details>
<summary><strong>4.7 Cinematics</strong></summary>

---

## Overview

```text
        Responsável por:
            - storytelling visual
            - transições
            - introduções
            - apresentação de rivais
```

### 4.7.1 Intro Sequences

#### Responsável por:

```text
                - introdução de eventos
                - establishing shots
                - pacing inicial
```

### 4.7.2 Rival Introductions

#### Responsável por:

```text
                - apresentação de bosses
                - crews
                - rivalidades
```

### 4.7.3 Transition Cinematics

#### Responsável por:

```text
                - transições suaves
                - carregamentos mascarados
```

### 4.7.4 Victory Sequences

#### Responsável por:

```text
                - celebração
                - recompensa emocional
```

</details>

---

<details>
<summary><strong>4.8 Photo Mode</strong></summary>

---

## Overview

```text
        Responsável por:
            - captura visual
            - screenshots
            - composição cinematográfica
```

### 4.8.1 Filters

#### Responsável por:

```text
                - color grading
                - LUTs
                - estilos visuais
```

### 4.8.2 DOF Controls

#### Responsável por:

```text
                - profundidade de campo
                - foco cinematográfico
```

### 4.8.3 Pose Controls

#### Responsável por:

```text
                - wheel angle
                - headlights
                - stance
```

</details>

---

<details>
<summary><strong>4.9 Accessibility</strong></summary>

---

## Overview

```text
        Responsável por:
            - acessibilidade
            - inclusão
            - legibilidade
```

### 4.9.1 Color Accessibility

#### Responsável por:

```text
                - colorblind modes
                - contraste
```

### 4.9.2 Subtitle System

#### Responsável por:

```text
                - legendas
                - rádio
                - diálogos
```

### 4.9.3 Input Accessibility

#### Responsável por:

```text
                - remapping
                - assistências
                - simplificação de inputs
```

</details>

---

</details>

---

<details>
<summary><strong>💻 Platform Layer</strong></summary>

```text
5. Platform Layer
├── Graphics API Layer
│   ├── DX12 Backend
│   ├── Vulkan Backend
│   ├── GPU Command System
│   └── Shader Interface
│
├── Input Layer
│   ├── Controller Support
│   ├── Keyboard/Mouse
│   ├── Steering Wheel Support
│   └── Input Mapping
│
├── File IO
│   ├── Async File Loading
│   ├── Save File Access
│   └── Package System
│
├── Threading
│   ├── Worker Threads
│   ├── Synchronization
│   ├── Thread Affinity
│   └── Fiber System
│
├── GPU Interface
│   ├── VRAM Management
│   ├── Texture Upload
│   └── Buffer Management
│
├── Platform Abstraction
│   ├── Windows Platform
│   ├── Console Platform
│   └── Platform Services
│
├── Network Sockets
│   ├── UDP Runtime
│   ├── TCP Runtime
│   ├── Packet Serialization
│   └── Network Encryption
│
└── Hardware APIs
    ├── Haptic APIs
    ├── Audio Device APIs
    ├── Telemetry Interfaces
    └── Performance Counters
```
### Responsibilities

- Hardware abstraction
- DX12/Vulkan
- Threading
- IO
- Networking
- GPU communication

# 5. Platform Layer

>Responsavel pela ligação do jogo ao hardware do usuario.

---

## Responsável por:

```text
        - abstração de hardware
        - integração com sistema operacional
        - APIs gráficas
        - threading de baixo nível
        - IO nativo
        - interface com GPU/CPU
```

---

## Objetivo:

```text
        - fornecer base multiplataforma
        - esconder diferenças de hardware
        - garantir estabilidade
        - garantir performance baixa latência
```

---

## NÃO deve:

```text
        - conter gameplay
        - conter lógica de corrida
        - conter IA
        - conter rendering de alto nível
```

---

<details>
<summary><strong>5.1 Graphics API Layer</strong></summary>

---

## Overview

```text
        Responsável por:
            - comunicação direta com GPU
            - command buffers
            - pipelines gráficos
            - sincronização GPU
```

### 5.1.1 DX12 Backend

#### Responsável por:

```text
                - implementação DirectX 12
                - command queues
                - descriptor heaps
                - resource barriers
```

### 5.1.2 Vulkan Backend

#### Responsável por:

```text
                - implementação Vulkan
                - multiplataforma
                - baixo overhead
```

### 5.1.3 GPU Command System

#### Responsável por:

```text
                - envio de comandos
                - sincronização CPU/GPU
                - command lists
```

### 5.1.4 Shader Interface

#### Responsável por:

```text
                - compilação
                - binding
                - reflection
                - cache de shaders
```

</details>

---

<details>
<summary><strong>5.2 Input Layer</strong></summary>

---

## Overview

```text
        Responsável por:
            - dispositivos de entrada
            - polling
            - abstração de controle
```

### 5.2.1 Controller Support

#### Responsável por:

```text
                - gamepads
                - triggers analógicos
                - force feedback
```

### 5.2.2 Keyboard/Mouse

#### Responsável por:

```text
                - inputs digitais
                - remapping
                - mouse raw input
```

### 5.2.3 Steering Wheel Support

#### Responsável por:

```text
                - force feedback avançado
                - rotação variável
                - pedais
                - H-shifter
```

#### Compatibilidade:

```text
                - Logitech
                - Thrustmaster
                - Fanatec
```

### 5.2.4 Input Mapping

#### Responsável por:

```text
                - bindings
                - profiles
                - presets
```

</details>

---

<details>
<summary><strong>5.3 File IO</strong></summary>

---

## Overview

```text
        Responsável por:
            - leitura/escrita
            - streaming de arquivos
            - acesso ao disco
```

### 5.3.1 Async File Loading

#### Responsável por:

```text
                - leitura assíncrona
                - prefetching
                - streaming contínuo
```

### 5.3.2 Save File Access

#### Responsável por:

```text
                - leitura de save
                - escrita segura
                - backup
```

### 5.3.3 Package System

#### Responsável por:

```text
                - containers de assets
                - arquivos compactados
                - lookup rápido
```

</details>

---

<details>
<summary><strong>5.4 Threading</strong></summary>

---

## Overview

```text
        Responsável por:
            - gerenciamento de threads
            - sincronização
            - paralelismo
```

### 5.4.1 Worker Threads

#### Responsável por:

```text
                - jobs paralelos
                - processamento background
```

### 5.4.2 Synchronization

#### Responsável por:

```text
                - mutexes
                - semaphores
                - barriers
                - locks
```

### 5.4.3 Thread Affinity

#### Responsável por:

```text
                - distribuição por core
                - otimização de cache
```

### 5.4.4 Fiber System

#### Responsável por:

```text
                - task switching leve
                - jobs de baixa latência
```

</details>

---

<details>
<summary><strong>5.5 GPU Interface</strong></summary>

---

## Overview

```text
        Responsável por:
            - gerenciamento de recursos gráficos
            - memória GPU
            - upload/download
```

### 5.5.1 VRAM Management

#### Responsável por:

```text
                - budget de memória
                - streaming GPU
```

### 5.5.2 Texture Upload

#### Responsável por:

```text
                - upload assíncrono
                - mip streaming
```

### 5.5.3 Buffer Management

#### Responsável por:

```text
                - vertex buffers
                - index buffers
                - constant buffers
```

</details>

---

<details>
<summary><strong>5.6 Platform Abstraction</strong></summary>

---

## Overview

```text
        Responsável por:
            - diferenças entre plataformas
            - APIs específicas
            - compatibilidade
```

### 5.6.1 Windows Platform

#### Responsável por:

```text
                - Win32
                - integração Windows
                - APIs específicas
```

### 5.6.2 Console Platform

#### Responsável por:

```text
                - APIs de console
                - otimizações específicas
```

### 5.6.3 Platform Services

#### Responsável por:

```text
                - achievements
                - cloud saves
                - friends
                - invites
```

</details>

---

<details>
<summary><strong>5.7 Network Sockets</strong></summary>

---

## Overview

```text
        Responsável por:
            - comunicação de rede
            - sockets
            - transporte de pacotes
```

### 5.7.1 UDP Runtime

#### Responsável por:

```text
                - gameplay networking
                - baixa latência
```

### 5.7.2 TCP Runtime

#### Responsável por:

```text
                - serviços confiáveis
                - autenticação
                - matchmaking
```

### 5.7.3 Packet Serialization

#### Responsável por:

```text
                - compactação
                - serialização binária
                - redução de bandwidth
```

### 5.7.4 Network Encryption

#### Responsável por:

```text
                - segurança
                - proteção de sessão
```

</details>

---

<details>
<summary><strong>5.8 Hardware APIs</strong></summary>

---

## Overview

```text
        Responsável por:
            - integração com hardware específico
            - APIs externas
            - recursos nativos
```

### 5.8.1 Haptic APIs

#### Responsável por:

```text
                - vibração
                - feedback tátil
                - adaptive triggers
```

### 5.8.2 Audio Device APIs

#### Responsável por:

```text
                - dispositivos de áudio
                - output switching
                - spatial hardware
```

### 5.8.3 Telemetry Interfaces

#### Responsável por:

```text
                - wheel telemetry
                - dashboards externos
                - APIs de sim racing
```

### 5.8.4 Performance Counters

#### Responsável por:

```text
                - métricas hardware
                - profiling baixo nível
                - monitoramento térmico
```

</details>

---

</details>

---
# Technology Stack


| Área | Tecnologia | Finalidade |
|---|---|---|
| Engine | Unreal Engine 5 | Base principal da engine |
| Linguagem | C++ | Gameplay e runtime |
| Rendering | DX12 + Vulkan | Renderização moderna |
| Physics | Chaos Modified | Física arcade customizada |
| Audio | Wwise | Áudio dinâmico |
| UI | UMG Custom | Interface e HUD |
| Networking | EOS / PlayFab | Multiplayer e backend |
| ECS | Custom Hybrid ECS | Arquitetura runtime |
| Profiling | Tracy + PIX + RenderDoc | Diagnóstico e profiling |
| Build System | Unreal Build Tool | Build pipeline |
| Source Control | Perforce | Controle de versão |
| CI/CD | Jenkins + GitHub Actions | Automação e integração contínua |

---
