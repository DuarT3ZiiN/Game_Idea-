# Engine Architecture

---

# Layers

<details>
<summary><strong>1. Game Layer</strong></summary>

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
│   ├── Scoring
│   │   ├── Position Scoring
│   │   ├── Drift Scoring
│   │   ├── Style Scoring
│   │   ├── Time Scoring
│   │   └── Combo System
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

</details>

---

<details>
<summary><strong>2. Simulation Layer</strong></summary>

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

</details>

---

<details>
<summary><strong>3. Core Layer</strong></summary>

```text
3. Core Layer
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

</details>

---

<details>
<summary><strong>4. Presentation Layer</strong></summary>

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

</details>

---

<details>
<summary><strong>5. Platform Layer</strong></summary>

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

</details>

---
# Technology Stack

| Area | Technology |
|---|---|
| Engine | Unreal Engine 5 |
| Language | C++ |
| Rendering | DX12 + Vulkan |
| Physics | Chaos Modified |
| Audio | Wwise |
| UI | UMG Custom |
| Networking | EOS / PlayFab |
| ECS | Custom Hybrid ECS |
| Profiling | Tracy + PIX + RenderDoc |
| Build System | Unreal Build Tool |
| Source Control | Perforce |
| CI/CD | Jenkins + GitHub Actions |

---

# 1. Game Layer

> Core gameplay orchestration layer.

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
                - scoring base
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

#### NÃO mede:

```text
                - posição
```

#### Mede:

```text
                    - ângulo
                    - velocidade lateral
                    - continuidade
                    - combos
```

#### Responsável por:

```text
                    - combo runtime
                    - drift chaining
                    - multiplier logic
                    - reset conditions
```

#### Drift bom:

```text
                    - parece técnico
                    - permanece controlável
                    - favorece flow
```

### 1.1.2.4 Drag Rules

#### Base:

```text
                    - inspirado em
                      -PRO STREET
```

#### Responsável por:

```text
                    - launch timing
                    - burnout state
                    - lane assist
                    - shift timing
                    - wheelspin
                    - trap speed
                    - nitro timing
```

#### Precisa:

```text
                    - sensação brutal de potência
                    - feedback visual forte
                    - câmera agressiva
                    - timing extremamente preciso
```

#### Estagios:

```text
                    - Burnout
                    - Stage
                    - Launch
                    - Shift
                    - Finish
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

### 1.1.3 Scoring

#### Responsável por:

```text
                - pontuação
                - rankings
                - multipliers
                - performance metrics
```

### 1.1.3.1 Position Scoring

#### Mede:

```text
                    - posição final
                    - ultrapassagens
                    - consistência
```

### 1.1.3.2 Drift Scoring

#### Mede:

```text
                    - ângulo
                    - velocidade
                    - combo
                    - continuidade
```

---

### 1.1.4 AI

#### Responsável por:

```text
                - comportamento competitivo
                - pacing
                - pressão psicológica
                - espetáculo cinematográfico
```

### 1.1.4.1 Race Director
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

### 1.1.4.2 Rubber Banding

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

### 1.1.4.3 Rival Behaviors

#### Responsável por:

```text
                    - rivalidade dinâmica
                    - targeting
                    - vingança
                    - intimidação
                    - defesa de posição
```

### 1.1.4.4 Tactical Driving

#### Responsável por:

```text
                    - bloqueios
                    - draft
                    - cutoff
                    - defesa
                    - pressão lateral
```

### 1.1.4.5 Aggression Profiles

#### Perfis:

```text
                    - Defensive
                    - Aggressive
                    - Technical
                    - Unstable
                    - Tactical
                    - Reckless
```


### 1.1.5 Crew Systems

#### Responsável por:

```text
                - coordenação em equipe
                - personalidade das crews
                - suporte tático
                - narrativa emergente
```

### 1.1.5.1 Tactical Roles

#### Papéis:

```text
                    - Blocker
                    - Drafter
                    - Scout
                    - Aggressor
```

### 1.1.5.2 Team Coordination

#### Responsável por:

```text
                    - coordenação contextual
                    - decisões cooperativas
                    - troca dinâmica de funções
```

### 1.1.5.3 Communication

#### Responsável por:

```text
                    - rádio
                    - callouts
                    - alertas
                    - informações de tráfego/polícia
```

### 1.1.5.4 Assist Logic

#### Responsável por:

```text
                    - abrir caminho
                    - proteger líder
                    - criar draft
                    - interromper rivais
```

### 1.1.5.5 Rival Crews

#### Responsável por:

```text
                    - identidade de crews
                    - reputação
                    - rivalidades persistentes
```

### 1.1.5.6 Personality Profiles

#### Mede:

```text

                    - agressividade
                    - coragem
                    - disciplina
                    - risco
                    - cooperação
```

---


### 1.1.6 Spawn Systems

#### Responsável por:

```text
                - posicionamento inicial
                - recuperação segura
                - validação espacial
                - controle de spawning dinâmico
                - prevenção de colisões de spawn
```

### 1.1.6.1 Grid Spawn

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

### 1.1.6.2 Recovery Spawn

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

### 1.1.6.3 Dynamic Spawn

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

### 1.1.6.4 Streaming Validation

#### Responsável por:

```text
                    - validar região carregada
                    - impedir spawn em unloaded areas
                    - validar memória disponível
```

---


### 1.1.7 Checkpoint Systems

#### Responsável por:

```text

                - progressão
                - validação de rota
                - detecção de exploits
                - controle de atalhos
```

### 1.1.7.1 Spline Progression

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

### 1.1.7.2 Checkpoint Validation

#### Responsável por:

```text
                    - validação sequencial
                    - checkpoint ordering
                    - fail states
                    - anti-skip
```

### 1.1.7.3 Shortcut Validation

#### Responsável por:

```text
                    - permitir atalhos legítimos
                    - bloquear exploits
                    - validar áreas opcionais
```

### 1.1.7.4 Anti-Cheat Logic

#### Detecta:

```text
                    - teleporte
                    - reversão ilegal
                    - skip de progresso
                    - velocidade impossível
```

---


### 1.1.8 Integrations

#### Responsável por:

```text
                - desacoplamento entre sistemas
                - comunicação indireta
                - adapters de runtime
```

### 1.1.8.1 Traffic Adapter

#### Responsável por:

```text
                    - sincronizar corrida/tráfego
                    - controlar densidade
                    - evitar caos excessivo
```

### 1.1.8.2 Police Adapter

#### Responsável por:

```text
                    - solicitar perseguições
                    - solicitar roadblocks
                    - injetar pressão policial
                    - sincronizar heat
```

### 1.1.8.3 Economy Adapter

#### Responsável por:

```text
                    - payout
                    - apostas
                    - reward scaling
                    - multas/danos
```

### 1.1.8.4 Mission Adapter

#### Responsável por:

```text
                    - objetivos especiais
                    - eventos dinâmicos
                    - missões híbridas
```

---


### 1.1.9 Rewards

#### Responsável por:

```text
                - progressão financeira
                - reputação
                - desbloqueios
                - scaling de recompensa
```

### 1.1.9.1 Cash Rewards

#### Baseado em:

```text
                    - posição
                    - dificuldade
                    - heat
                    - clean racing
                    - style
```

### 1.1.9.2 Reputation Rewards

#### Mede:

```text
                    - notoriedade
                    - estilo
                    - domínio territorial
                    - vitórias importantes
```

### 1.1.9.3 Crew Reputation

#### Responsável por:

```text
                    - reputação coletiva
                    - influência da crew
                    - rivalidades
```

### 1.1.9.4 Unlock System

#### Responsável por:

```text
                    - carros
                    - peças
                    - eventos
                    - sponsors
                    - áreas da cidade
```

---

### 1.1.10 Telemetry

#### Responsável por:

```text
                - analytics
                - balancing
                - tuning de IA
                - métricas de gameplay
```

### 1.1.10.1 Heatmaps

#### Mede:

```text
                    - crashes
                    - atalhos
                    - zonas difíceis
                    - tráfego problemático
```

### 1.1.10.2 Difficulty Metrics

#### Mede:

```text
                    - win rate
                    - retry rate
                    - abandono
                    - dificuldade percebida
```

### 1.1.10.3 Crash Analytics

#### Mede:

```text
                    - frequência
                    - intensidade
                    - causas
                    - zonas críticas
```

### 1.1.10.4 AI Performance

#### Mede:

```text
                    - eficiência
                    - agressividade
                    - ultrapassagens
                    - rubber banding effectiveness
```

---

### 1.1.11 Online

#### Responsável por:

```text
                - sincronização online
                - sessões multiplayer
                - replicação
                - ghosts
                - matchmaking runtime
```

### 1.1.11.1 Synchronization

#### Responsável por:

```text
                    - sincronização de estado
                    - latency compensation
                    - prediction
                    - reconciliation
```

### 1.1.11.2 Ghost System

#### Responsável por:

```text
                    - replay competitivo
                    - time attack ghosts
                    - records assíncronos
```

### 1.1.11.3 Match Runtime

#### Responsável por:

```text
                    - lifecycle multiplayer
                    - lobby states
                    - matchmaking flow
```

### 1.1.11.4 Replication

#### Responsável por:

```text
                    - replicação de veículos
                    - replicação de polícia
                    - replicação de eventos
                    - state authority
```

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

---


    1.7 Global Director
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


        1.7.1 World Pacing
            Responsável por:
                - alternância de intensidade
                - descanso emocional
                - escalada de tensão

            Objetivo:
                - evitar fadiga constante
                - manter flow cinematográfico


        1.7.2 Dynamic Intensity
            Mede:
                - performance do jogador
                - caos atual
                - nível de pressão
                - risco percebido

            Ajusta:
                - agressividade
                - spawn rates
                - frequência de eventos


        1.7.3 Traffic Density
            Responsável por:
                - densidade global
                - distribuição urbana
                - pacing de tráfego


        1.7.4 Police Pressure
            Responsável por:
                - pressão policial macro
                - saturação de perseguições
                - heat regional


        1.7.5 Audio Intensity
            Responsável por:
                - intensidade musical
                - layering de soundtrack
                - transições sonoras

            Deve responder:
                - velocidade
                - perseguição
                - tensão
                - risco


        1.7.6 Event Orchestration
            Responsável por:
                - sincronização de grandes eventos
                - pacing cinematográfico
                - controle de espetáculo

            Exemplos:
                - blackout durante pursuit
                - tempestade iniciando em corrida
                - lockdown policial
                - entrada de rival crew

1. Simulation Layer
    Responsável por:
        - simulação física
        - comportamento matemático
        - runtime de IA
        - movimentação
        - colisões
        - navegação
        - streaming operacional

    NÃO deve:
        - conter regras de gameplay
        - controlar progressão
        - controlar narrativa
        - controlar pacing cinematográfico

    Objetivo:
        - fornecer simulação consistente
        - manter previsibilidade sistêmica
        - sustentar gameplay emergente



    2.1 Vehicle Simulation
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


        2.1.1 Tire Model
            Responsável por:
                - aderência
                - perda de tração
                - slip angles
                - comportamento lateral

            Deve controlar:
                - grip progressivo
                - breakaway previsível
                - recuperação controlável


        2.1.2 Suspension
            Responsável por:
                - absorção de impacto
                - transferência de peso
                - estabilidade

            Deve influenciar:
                - drift
                - curvas
                - sensação de velocidade


        2.1.3 Differential
            Responsável por:
                - distribuição de torque
                - comportamento em aceleração
                - estabilidade de saída de curva


        2.1.4 Weight Transfer
            Responsável por:
                - movimentação dinâmica de massa
                - sensação de peso
                - estabilidade

            Deve:
                - parecer real
                - permanecer arcade


        2.1.5 Drift Assist
            Responsável por:
                - estabilidade de drift
                - transições
                - countersteering assist

            NÃO deve:
                - dirigir pelo jogador
                - parecer automático


        2.1.6 Stability Assist
            Responsável por:
                - recuperação de controle
                - estabilidade em alta velocidade
                - suavização de inputs


        2.1.7 Traction Assist
            Responsável por:
                - controle de wheelspin
                - saída de curva
                - launches


        2.1.8 Aero Simulation
            Responsável por:
                - downforce
                - drag aerodinâmico
                - estabilidade em alta velocidade


        2.1.9 Surface Response
            Responsável por:
                - resposta do veículo ao terreno

            Superfícies:
                - asfalto
                - concreto
                - terra
                - água
                - óleo
                - grama


        2.1.10 Collision Solver
            Responsável por:
                - impactos
                - transferência de força
                - deformações simplificadas

            Objetivo:
                - impacto cinematográfico
                - feedback visual forte


        2.1.11 Damage Simulation
            Responsável por:
                - dano mecânico
                - dano visual
                - degradação operacional

            Pode afetar:
                - velocidade
                - steering
                - aceleração
                - estabilidade



    2.2 Traffic Simulation
        Responsável por:
            - veículos civis
            - fluxo urbano
            - comportamento ambiental


        2.2.1 Lane System
            Responsável por:
                - lanes
                - fluxo de trânsito
                - organização viária


        2.2.2 Traffic Behaviors
            Responsável por:
                - aceleração
                - frenagem
                - trocas de faixa
                - reação ao jogador


        2.2.3 Avoidance System
            Responsável por:
                - evasão de colisões
                - prevenção de deadlocks
                - resposta emergencial


        2.2.4 Density Solver
            Responsável por:
                - densidade de veículos
                - distribuição dinâmica
                - controle de carga computacional


        2.2.5 Intersection Logic
            Responsável por:
                - cruzamentos
                - prioridade
                - semáforos
                - bloqueios



    2.3 AI Simulation
        Responsável por:
            - tomada de decisão
            - navegação
            - comportamento contextual
            - processamento de IA


        2.3.1 Navigation Runtime
            Responsável por:
                - navegação em mundo aberto
                - rotas
                - atualização dinâmica


        2.3.2 Pathfinding
            Responsável por:
                - cálculo de caminhos
                - rotas alternativas
                - desvios contextuais

            NÃO deve:
                - recalcular tudo constantemente


        2.3.3 Utility AI
            Responsável por:
                - decisões contextuais
                - avaliação de utilidade
                - prioridades dinâmicas

            Melhor para:
                - racers
                - polícia
                - crews


        2.3.4 Behavior Trees
            Responsável por:
                - comportamento procedural
                - execução hierárquica
                - sequências táticas


        2.3.5 Decision Scheduler
            Responsável por:
                - distribuição de processamento
                - frequência de atualização
                - otimização de IA

            Objetivo:
                - evitar gargalos CPU



    2.4 World Streaming
        Responsável por:
            - carregamento do mundo
            - descarregamento
            - memória
            - streaming assíncrono

        Objetivo:
            - eliminar loading perceptível
            - manter performance estável


        2.4.1 District Streaming
            Responsável por:
                - carregamento regional
                - transição de distritos


        2.4.2 LOD Manager
            Responsável por:
                - level of detail
                - redução de custo gráfico
                - troca dinâmica de assets


        2.4.3 Async Loading
            Responsável por:
                - carregamento assíncrono
                - preloading
                - streaming preditivo


        2.4.4 Occlusion System
            Responsável por:
                - ocultação
                - redução de draw calls
                - economia de GPU


        2.4.5 Asset Streaming
            Responsável por:
                - texturas
                - meshes
                - áudio
                - efeitos


        2.4.6 Memory Budgeting
            Responsável por:
                - limite de memória
                - descarregamento inteligente
                - prevenção de overflow



    2.5 Physics Runtime
        Responsável por:
            - física global
            - colisões
            - queries físicas
            - constraints


        2.5.1 Broadphase
            Responsável por:
                - filtragem inicial de colisões
                - redução de custo computacional


        2.5.2 Narrowphase
            Responsável por:
                - resolução precisa de colisões
                - contatos detalhados


        2.5.3 Constraint Solver
            Responsável por:
                - juntas
                - suspensão
                - conexões físicas


        2.5.4 Raycasts
            Responsável por:
                - detecção de superfície
                - sensores
                - IA
                - suspensão


        2.5.5 Collision Queries
            Responsável por:
                - overlap tests
                - sweep tests
                - spatial queries

3. Core Layer
    Responsável por:
        - infraestrutura central
        - comunicação sistêmica
        - gerenciamento de runtime
        - persistência
        - execução assíncrona
        - authority global

    Objetivo:
        - sustentar todos os layers
        - evitar acoplamento direto
        - garantir escalabilidade
        - garantir estabilidade operacional

    NÃO deve:
        - conter gameplay
        - conter regras de corrida
        - conter narrativa
        - conter lógica visual



    3.1 ECS Runtime
        Responsável por:
            - gerenciamento de entidades
            - components
            - systems
            - processamento massivo

        Objetivo:
            - escalabilidade
            - paralelismo
            - performance


        3.1.1 Entities
            Representam:
                - carros
                - polícia
                - tráfego
                - objetos
                - triggers


        3.1.2 Components
            Contêm:
                - dados puros
                - estado
                - configuração

            NÃO devem:
                - possuir lógica pesada


        3.1.3 Systems
            Responsáveis por:
                - processamento
                - execução paralela
                - atualização de entidades


        3.1.4 Archetypes
            Responsáveis por:
                - agrupamento eficiente
                - cache locality
                - performance massiva



    3.2 Event Bus
        Responsável por:
            - comunicação desacoplada
            - propagação de eventos
            - integração sistêmica

        Objetivo:
            - evitar dependência direta
            - facilitar replay
            - facilitar telemetry
            - facilitar online


        3.2.1 Global Events
            Exemplos:
                - OnRaceStart
                - OnPursuitBegin
                - OnPlayerCrash
                - OnDistrictLoaded


        3.2.2 Local Events
            Responsáveis por:
                - eventos regionais
                - eventos temporários
                - comunicação contextual


        3.2.3 Async Queue
            Responsável por:
                - processamento assíncrono
                - buffering
                - ordenação


        3.2.4 Event Priorities
            Prioridades:
                - Critical
                - High
                - Normal
                - Background



    3.3 State Machine Framework
        Responsável por:
            - controle de estados
            - transições
            - validação de runtime

        Objetivo:
            - previsibilidade
            - estabilidade
            - prevenção de estados inválidos


        3.3.1 Global States
            Exemplos:
                - MainMenu
                - FreeRoam
                - Race
                - Pursuit
                - Garage


        3.3.2 Local States
            Exemplos:
                - Countdown
                - DriftChain
                - SearchMode


        3.3.3 Transition Rules
            Responsável por:
                - validar transições
                - impedir estados ilegais



    3.4 Task Scheduler
        Responsável por:
            - distribuição de tarefas
            - balanceamento de carga
            - atualização de sistemas

        Objetivo:
            - evitar gargalos
            - otimizar CPU
            - escalabilidade multicore


        3.4.1 Job Distribution
            Responsável por:
                - distribuição paralela
                - worker threads


        3.4.2 Priority Scheduling
            Prioridades:
                - gameplay crítico
                - física
                - IA
                - background


        3.4.3 Runtime Budgeting
            Responsável por:
                - limitar custo de frame
                - controlar overload



    3.5 Async Job System
        Responsável por:
            - tarefas assíncronas
            - IO
            - streaming
            - cálculos pesados


        3.5.1 Background Jobs
            Exemplos:
                - loading
                - compressão
                - analytics


        3.5.2 Thread Pools
            Responsável por:
                - reutilização de threads
                - otimização de CPU



    3.6 Save System
        Responsável por:
            - persistência
            - serialização
            - carregamento

        Objetivo:
            - salvar estado global
            - suportar mundo persistente


        3.6.1 Player Save
            Contém:
                - progressão
                - carros
                - dinheiro
                - reputação


        3.6.2 World Save
            Contém:
                - estado do mundo
                - eventos ativos
                - mudanças persistentes


        3.6.3 Serialization
            Responsável por:
                - compactação
                - escrita eficiente
                - leitura segura


        3.6.4 Versioning
            Responsável por:
                - compatibilidade
                - migração de save
                - patches futuros



    3.7 Replay Runtime
        Responsável por:
            - gravação temporal
            - playback
            - replay cinematográfico


        3.7.1 Input Recording
            Responsável por:
                - inputs do jogador
                - sincronização temporal


        3.7.2 State Recording
            Responsável por:
                - transforms
                - velocidade
                - eventos importantes


        3.7.3 Playback Runtime
            Responsável por:
                - reprodução
                - sincronização
                - timeline


        3.7.4 Replay Cameras
            Responsável por:
                - câmeras cinematográficas
                - cortes dinâmicos
                - tracking



    3.8 Replication Layer
        Responsável por:
            - sincronização online
            - authority
            - estado de rede


        3.8.1 State Replication
            Responsável por:
                - replicar entidades
                - replicar estados críticos


        3.8.2 Prediction
            Responsável por:
                - client prediction
                - suavização


        3.8.3 Reconciliation
            Responsável por:
                - correção de desync
                - validação de authority


        3.8.4 Network Priority
            Prioriza:
                - player
                - polícia próxima
                - racers próximos



    3.9 Resource Manager
        Responsável por:
            - gerenciamento de assets
            - memória
            - cache

        Objetivo:
            - evitar duplicação
            - otimizar carregamento


        3.9.1 Asset References
            Responsável por:
                - referências seguras
                - controle de uso


        3.9.2 Runtime Cache
            Responsável por:
                - cache inteligente
                - reutilização


        3.9.3 Memory Tracking
            Responsável por:
                - monitoramento de memória
                - prevenção de leaks



    3.10 Asset Registry
        Responsável por:
            - catalogar assets
            - lookup
            - metadata


        3.10.1 Vehicle Assets
            Contém:
                - carros
                - peças
                - tuning


        3.10.2 World Assets
            Contém:
                - distritos
                - props
                - tráfego


        3.10.3 Audio Assets
            Contém:
                - música
                - rádio
                - FX



    3.11 Data Serialization
        Responsável por:
            - conversão de dados
            - persistência binária
            - compactação


        3.11.1 Binary Serialization
            Objetivo:
                - performance
                - baixo custo


        3.11.2 Config Serialization
            Responsável por:
                - configs
                - tuning
                - balancing



    3.12 Config Runtime
        Responsável por:
            - configuração dinâmica
            - balancing
            - tuning em runtime


        3.12.1 Gameplay Configs
            Controla:
                - drift assist
                - heat
                - rewards


        3.12.2 AI Configs
            Controla:
                - agressividade
                - reaction times
                - pursuit pressure


        3.12.3 Economy Configs
            Controla:
                - preços
                - scaling
                - payouts



    3.13 Debug/Profiling Tools
        Responsável por:
            - debugging
            - profiling
            - análise de performance


        3.13.1 Performance Metrics
            Mede:
                - frametime
                - CPU
                - GPU
                - streaming cost


        3.13.2 AI Debug
            Mostra:
                - decisões
                - pathfinding
                - targeting


        3.13.3 Physics Debug
            Mostra:
                - colisões
                - suspensão
                - raycasts


        3.13.4 Streaming Debug
            Mostra:
                - carregamento
                - memória
                - LOD transitions



    3.14 Memory Manager
        Responsável por:
            - alocação
            - pools
            - fragmentação

        Objetivo:
            - estabilidade
            - previsibilidade
            - baixo overhead


        3.14.1 Pool Allocators
            Responsável por:
                - allocations rápidas
                - reutilização


        3.14.2 Streaming Memory
            Responsável por:
                - budget de streaming
                - descarregamento


        3.14.3 Leak Detection
            Responsável por:
                - detectar vazamentos
                - rastrear referências

4. Presentation Layer
    Responsável por:
        - apresentação visual
        - feedback audiovisual
        - cinematografia
        - HUD
        - câmera
        - efeitos
        - sensação de impacto

    Objetivo:
        - transformar simulação em espetáculo
        - aumentar percepção de velocidade
        - reforçar identidade visual
        - elevar intensidade emocional

    NÃO deve:
        - conter regras de gameplay
        - conter física
        - conter lógica de progressão
        - controlar authority sistêmica



    4.1 Rendering
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


        4.1.1 Lighting System
            Responsável por:
                - iluminação global
                - iluminação dinâmica
                - headlights
                - neon
                - emissive lighting

            Deve priorizar:
                - atmosfera
                - leitura visual
                - contraste cinematográfico


        4.1.2 Post Processing
            Responsável por:
                - motion blur
                - bloom
                - chromatic aberration
                - exposure
                - tone mapping

            Objetivo:
                - sensação extrema de velocidade
                - agressividade visual


        4.1.3 Material System
            Responsável por:
                - paint shaders
                - wet surfaces
                - reflections
                - metallic response


        4.1.4 Reflection System
            Responsável por:
                - SSR
                - cubemaps
                - reflections dinâmicas

            Importante para:
                - carros
                - chuva
                - cidade noturna


        4.1.5 Shadow System
            Responsável por:
                - sombras dinâmicas
                - headlights shadows
                - sombras urbanas


        4.1.6 Environment Rendering
            Responsável por:
                - cidade
                - skyline
                - horizonte
                - atmosfera urbana



    4.2 Camera Systems
        Responsável por:
            - framing
            - percepção de velocidade
            - cinematografia
            - feedback contextual


        4.2.1 Gameplay Camera
            Responsável por:
                - câmera principal
                - estabilidade visual
                - leitura de gameplay

            Deve:
                - transmitir velocidade
                - permanecer legível


        4.2.2 Drift Camera
            Responsável por:
                - ângulo cinematográfico
                - amplificação visual do drift
                - tracking lateral


        4.2.3 Pursuit Camera
            Responsável por:
                - sensação de perseguição
                - tensão
                - impacto

            Deve:
                - parecer agressiva
                - aumentar intensidade


        4.2.4 Crash Camera
            Responsável por:
                - slow motion
                - impacto visual
                - dramaticidade


        4.2.5 Replay Camera
            Responsável por:
                - câmeras cinematográficas
                - cortes dinâmicos
                - tracking inteligente


        4.2.6 Photo Mode Camera
            Responsável por:
                - câmera livre
                - DOF
                - composição visual



    4.3 UI/HUD
        Responsável por:
            - interface
            - feedback ao jogador
            - leitura rápida
            - telemetria visual

        Objetivo:
            - legibilidade extrema
            - baixa distração
            - resposta rápida


        4.3.1 Race HUD
            Contém:
                - velocidade
                - posição
                - minimap
                - nitro
                - checkpoints


        4.3.2 Pursuit HUD
            Contém:
                - heat
                - status policial
                - cooldown
                - unidades ativas


        4.3.3 Drift HUD
            Contém:
                - combo
                - multiplicador
                - ângulo
                - score


        4.3.4 Navigation HUD
            Responsável por:
                - GPS
                - rotas
                - guidance dinâmica


        4.3.5 Online HUD
            Contém:
                - ping
                - posição online
                - players próximos


        4.3.6 Garage UI
            Responsável por:
                - tuning
                - customização
                - marketplace



    4.4 VFX
        Responsável por:
            - partículas
            - fumaça
            - sparks
            - explosões visuais
            - feedback de velocidade


        4.4.1 Nitro Effects
            Responsável por:
                - flames
                - distortion
                - boost visuals


        4.4.2 Drift Effects
            Responsável por:
                - fumaça
                - skid marks
                - partículas laterais


        4.4.3 Weather Effects
            Responsável por:
                - chuva
                - água
                - respingos
                - neblina


        4.4.4 Damage Effects
            Responsável por:
                - debris
                - sparks
                - peças soltas


        4.4.5 Environmental FX
            Responsável por:
                - poeira
                - lixo urbano
                - vento
                - folhas



    4.5 Audio Runtime
        Responsável por:
            - áudio procedural
            - spatial audio
            - mixagem dinâmica
            - feedback sonoro

        Objetivo:
            - sensação mecânica brutal
            - pressão sonora
            - intensidade emocional


        4.5.1 Engine Audio
            Responsável por:
                - RPM blending
                - turbo
                - transmission whine
                - intake
                - exhaust


        4.5.2 Pursuit Audio
            Responsável por:
                - sirenes
                - rádio policial
                - tensão sonora


        4.5.3 Impact Audio
            Responsável por:
                - colisões
                - metal
                - destruição


        4.5.4 Environment Audio
            Responsável por:
                - cidade
                - túneis
                - chuva
                - crowd ambience


        4.5.5 Spatial Audio
            Responsável por:
                - posicionamento 3D
                - doppler
                - distância sonora



    4.6 Music Director
        Responsável por:
            - soundtrack dinâmica
            - intensidade musical
            - layering adaptativo

        Objetivo:
            - sincronizar emoção e gameplay


        4.6.1 Dynamic Layers
            Responsável por:
                - adicionar/remover camadas musicais
                - escalada de intensidade


        4.6.2 Pursuit Music
            Responsável por:
                - tensão policial
                - escalada sonora


        4.6.3 Race Music
            Responsável por:
                - intensidade competitiva
                - ritmo


        4.6.4 Ambient Music
            Responsável por:
                - exploração
                - calmaria
                - atmosfera urbana



    4.7 Cinematics
        Responsável por:
            - storytelling visual
            - transições
            - introduções
            - apresentação de rivais


        4.7.1 Intro Sequences
            Responsável por:
                - introdução de eventos
                - establishing shots
                - pacing inicial


        4.7.2 Rival Introductions
            Responsável por:
                - apresentação de bosses
                - crews
                - rivalidades


        4.7.3 Transition Cinematics
            Responsável por:
                - transições suaves
                - carregamentos mascarados


        4.7.4 Victory Sequences
            Responsável por:
                - celebração
                - recompensa emocional



    4.8 Photo Mode
        Responsável por:
            - captura visual
            - screenshots
            - composição cinematográfica


        4.8.1 Filters
            Responsável por:
                - color grading
                - LUTs
                - estilos visuais


        4.8.2 DOF Controls
            Responsável por:
                - profundidade de campo
                - foco cinematográfico


        4.8.3 Pose Controls
            Responsável por:
                - wheel angle
                - headlights
                - stance



    4.9 Accessibility
        Responsável por:
            - acessibilidade
            - inclusão
            - legibilidade


        4.9.1 Color Accessibility
            Responsável por:
                - colorblind modes
                - contraste


        4.9.2 Subtitle System
            Responsável por:
                - legendas
                - rádio
                - diálogos


        4.9.3 Input Accessibility
            Responsável por:
                - remapping
                - assistências
                - simplificação de inputs

5. Platform Layer
    Responsável por:
        - abstração de hardware
        - integração com sistema operacional
        - APIs gráficas
        - threading de baixo nível
        - IO nativo
        - interface com GPU/CPU

    Objetivo:
        - fornecer base multiplataforma
        - esconder diferenças de hardware
        - garantir estabilidade
        - garantir performance baixa latência

    NÃO deve:
        - conter gameplay
        - conter lógica de corrida
        - conter IA
        - conter rendering de alto nível



    5.1 Graphics API Layer
        Responsável por:
            - comunicação direta com GPU
            - command buffers
            - pipelines gráficos
            - sincronização GPU


        5.1.1 DX12 Backend
            Responsável por:
                - implementação DirectX 12
                - command queues
                - descriptor heaps
                - resource barriers


        5.1.2 Vulkan Backend
            Responsável por:
                - implementação Vulkan
                - multiplataforma
                - baixo overhead


        5.1.3 GPU Command System
            Responsável por:
                - envio de comandos
                - sincronização CPU/GPU
                - command lists


        5.1.4 Shader Interface
            Responsável por:
                - compilação
                - binding
                - reflection
                - cache de shaders



    5.2 Input Layer
        Responsável por:
            - dispositivos de entrada
            - polling
            - abstração de controle


        5.2.1 Controller Support
            Responsável por:
                - gamepads
                - triggers analógicos
                - force feedback


        5.2.2 Keyboard/Mouse
            Responsável por:
                - inputs digitais
                - remapping
                - mouse raw input


        5.2.3 Steering Wheel Support
            Responsável por:
                - force feedback avançado
                - rotação variável
                - pedais
                - H-shifter

            Compatibilidade:
                - Logitech
                - Thrustmaster
                - Fanatec


        5.2.4 Input Mapping
            Responsável por:
                - bindings
                - profiles
                - presets



    5.3 File IO
        Responsável por:
            - leitura/escrita
            - streaming de arquivos
            - acesso ao disco


        5.3.1 Async File Loading
            Responsável por:
                - leitura assíncrona
                - prefetching
                - streaming contínuo


        5.3.2 Save File Access
            Responsável por:
                - leitura de save
                - escrita segura
                - backup


        5.3.3 Package System
            Responsável por:
                - containers de assets
                - arquivos compactados
                - lookup rápido



    5.4 Threading
        Responsável por:
            - gerenciamento de threads
            - sincronização
            - paralelismo


        5.4.1 Worker Threads
            Responsável por:
                - jobs paralelos
                - processamento background


        5.4.2 Synchronization
            Responsável por:
                - mutexes
                - semaphores
                - barriers
                - locks


        5.4.3 Thread Affinity
            Responsável por:
                - distribuição por core
                - otimização de cache


        5.4.4 Fiber System
            Responsável por:
                - task switching leve
                - jobs de baixa latência



    5.5 GPU Interface
        Responsável por:
            - gerenciamento de recursos gráficos
            - memória GPU
            - upload/download


        5.5.1 VRAM Management
            Responsável por:
                - budget de memória
                - streaming GPU


        5.5.2 Texture Upload
            Responsável por:
                - upload assíncrono
                - mip streaming


        5.5.3 Buffer Management
            Responsável por:
                - vertex buffers
                - index buffers
                - constant buffers



    5.6 Platform Abstraction
        Responsável por:
            - diferenças entre plataformas
            - APIs específicas
            - compatibilidade


        5.6.1 Windows Platform
            Responsável por:
                - Win32
                - integração Windows
                - APIs específicas


        5.6.2 Console Platform
            Responsável por:
                - APIs de console
                - otimizações específicas


        5.6.3 Platform Services
            Responsável por:
                - achievements
                - cloud saves
                - friends
                - invites



    5.7 Network Sockets
        Responsável por:
            - comunicação de rede
            - sockets
            - transporte de pacotes


        5.7.1 UDP Runtime
            Responsável por:
                - gameplay networking
                - baixa latência


        5.7.2 TCP Runtime
            Responsável por:
                - serviços confiáveis
                - autenticação
                - matchmaking


        5.7.3 Packet Serialization
            Responsável por:
                - compactação
                - serialização binária
                - redução de bandwidth


        5.7.4 Network Encryption
            Responsável por:
                - segurança
                - proteção de sessão



    5.8 Hardware APIs
        Responsável por:
            - integração com hardware específico
            - APIs externas
            - recursos nativos


        5.8.1 Haptic APIs
            Responsável por:
                - vibração
                - feedback tátil
                - adaptive triggers


        5.8.2 Audio Device APIs
            Responsável por:
                - dispositivos de áudio
                - output switching
                - spatial hardware


        5.8.3 Telemetry Interfaces
            Responsável por:
                - wheel telemetry
                - dashboards externos
                - APIs de sim racing


        5.8.4 Performance Counters
            Responsável por:
                - métricas hardware
                - profiling baixo nível
                - monitoramento térmico
```