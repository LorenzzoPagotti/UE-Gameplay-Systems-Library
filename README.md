# Unreal Engine C++ Gameplay Library

Welcome to my C++ Gameplay Systems Library for Unreal Engine. This repository is a curated collection of modular, reusable, and performant gameplay systems, all built from the ground up in C++. Each system is designed with professional practices in mind, focusing on efficiency, flexibility, and ease of use for designers.

This project serves as a living portfolio of my work as a Gameplay Programmer.

---

## Systems Included

This library currently contains the following systems:

### 1. AI System (Patrol & Chase)
A foundational AI system featuring a custom C++ AI Controller that uses Unreal's Perception System and a Behavior Tree to drive behavior. The AI autonomously patrols an area, detects players via sight, and gives chase. If the AI loses sight, it instantly go to the last known location and start searching for the player.

* **Key Source Files:**
    * [`ACustomAIController.h`](Source/NewPortfolio/Public/CustomAIController.h)
    * [`ACustomAIController.cpp`](Source/NewPortfolio/Private/CustomAIController.cpp)
    * [`BTTask_FindRandomPatrolLocation.cpp`](Source/NewPortfolio/Private/BTTask_FindRandomPatrolLocation.cpp)
    * [`BTTask_ChangeSpeed.cpp`](Source/NewPortfolio/Private/BTTask_ChangeSpeed.cpp)
    * [`BTTask_Attack.cpp`](Source/NewPortfolio/Private/BTTask_Attack.cpp)

* **Features:**
    * Custom C++ `AIController` as the AI's "brain".
    * Optimized player detection using `AIPerceptionComponent` (Sight and Hearing).
    * Modular logic via `Behavior Tree` and `Blackboard`.
    * Custom C++ `BTTasks` for actions like finding valid patrol points on the NavMesh and changing speed.
    * Highly configurable in the editor, using `FName` variables for Blackboard keys to avoid hard-coded strings.

### 2. Modular Interaction System
A flexible, event-driven interaction component. It allows any character to interact with any object in the world through a C++ Interface, using Delegates for clean communication with UI and other systems.

* **Key Source Files:**
    * [`UInteractionComponent.h`](Source/NewPortfolio/Public/InteractionComponent.h)
    * [`UInteractionComponent.cpp`](Source/NewPortfolio/Private/InteractionComponent.cpp)
    * [`BaseInteractableActor.h`](Source/NewPortfolio/Public/BaseInteractableActor.h)
    * [`BaseInteractableActor.cpp`](Source/NewPortfolio/Private/BaseInteractableActor.cpp)
    * (Requires an `InteractionInterface` to be implemented on Actors that are not parent from BaseInteractableActor)*

* **Features:**
    * **Component-based:** Add the component to any actor to give it interaction capabilities.
    * **Delegate-driven:** Uses `Delegates` to broadcast focus changes, cleanly decoupling the system from the UI.
    * **Performant:** Uses a `Timer` instead of `Tick` for focus detection.
    * **Flexible:** Works with any actor that implements the required C++ or Blueprint interface.

### 3. Sprint & Stamina Component
A plug-and-play Actor Component that adds a complete stamina and sprint mechanic to any character. All parameters are exposed to Blueprints for easy tweaking by designers.

* **Key Source Files:**
    * [`UStaminaComponent.h`](Source/NewPortfolio/Public/StaminaComponent.h)
    * [`UStaminaComponent.cpp`](Source/NewPortfolio/Private/StaminaComponent.cpp)

* **Features:**
    * Written in C++ for maximum performance.
    * Plug-and-play design.
    * All variables (`MaxStamina`, `RegenRate`, `SprintSpeed`, etc.) are exposed to Blueprints for easy iteration.
 
### 4. Health Component
A plug-and-play Actor Component that adds a modular Health system to any character. All parameters, functions and variables are exposed to Blueprints for easy tweaking by designers and rapid iterations.

* **Key Source Files:**
    * [`UHealthComponent.h`](Source/NewPortfolio/Public/HealthComponent.h)
    * [`UHealthComponent.cpp`](Source/NewPortfolio/Private/HealthComponent.cpp)
    * [`UHealthInterface.h`](Source/NewPortfolio/Public/HealthInterface.h)
    * [`UHealthInterface.cpp`](Source/NewPortfolio/Private/HealthInterface.cpp)

* **Features:**
    * Written in C++ for maximum performance.
    * Plug-and-play design.
    * All variables (`MaxHealth`, `MinHealth`, `IsDead`, etc.) are exposed to Blueprints for easy iteration.
    * All functions (`Die()`, `DamagePlayer()`, `HealPlayer()`, etc.) are all exposed to blueprints.
 
### 5. Inventory Component
A plug-and-play Actor Component that adds a complete modular Inventory System to any Actor you want. All parameters are exposed to Blueprints for easy tweaking by designers.

* **Key Source Files:**
    * [`UInventoryComponent.h`](Source/NewPortfolio/Public/InventoryComponent.h)
    * [`UInventoryComponent.cpp`](Source/NewPortfolio/Private/InventoryComponent.cpp)
    * [`UInventoryInterface.h`](Source/NewPortfolio/Public/InventoryInterface.h)
    * [`UInventoryInterface.cpp`](Source/NewPortfolio/Private/InventoryInterface.cpp)
    * [`UItemType.h`](Source/NewPortfolio/Public/ItemType.h)
    * [`UItemType.cpp`](Source/NewPortfolio/Private/ItemType.cpp)
    * [`UInventoryDataAsset.h`](Source/NewPortfolio/Public/InventoryDataAsset.h)
    * [`UInventoryDataAsset.cpp`](Source/NewPortfolio/Private/InventoryDataAsset.cpp)
 
  * **Features:**
    * Clean communication via Items/Player/Events without using hard references like `CASTING`. All communications are via `Interfaces`.
    * Written in C++ for maximum performance.
    * Plug-and-play design.
    * All variables are exposed to Blueprints for easy iteration.
    * All functions are all exposed to blueprints.
    * Most of the events can be changed via blueprints, using custom functions made by me in C++.
 
---

## How to Use This Repository

This is a complete and functional Unreal Engine project that serves as a showroom for the systems above.
1.  Clone the repository.
2.  Generate Visual Studio project files.
3.  Open the `.uproject` file and explore the demonstration map.

To migrate a component to your own project, you would need to copy the relevant source files (`.h` and `.cpp`) and ensure any necessary module dependencies (like `AIModule` or `NavigationSystem`) are added to your project's `.Build.cs` file.

<br>

<details>
<summary><strong>Ver em Português 🇧🇷</strong></summary>

# Biblioteca de Sistemas de Gameplay em C++ para Unreal Engine

Bem-vindo à minha Biblioteca de Sistemas de Gameplay em C++ para a Unreal Engine. Este repositório é uma coleção de sistemas de gameplay modulares, reutilizáveis e performáticos, todos construídos do zero em C++. Cada sistema foi projetado com práticas profissionais em mente, focando em eficiência, flexibilidade e facilidade de uso para designers.

Este projeto serve como um portfólio vivo do meu trabalho como Programador de Gameplay.

---

## Sistemas Incluídos

Atualmente, esta biblioteca contém os seguintes sistemas:

### 1. Sistema de IA (Patrulha e Perseguição)
Um sistema de IA fundamental que apresenta um `AIController` customizado em C++ que usa o Sistema de Percepção da Unreal e uma `Behavior Tree` para guiar o comportamento. A IA patrulha uma área de forma autônoma, detecta jogadores através da visão e os persegue. Se ela perder o jogador de vista, ela instantaneamente vai até a última localização conhecida do jogador e procura pelo jogador.

* **Principais Arquivos de Código:**
    * [`ACustomAIController.h`](Source/NewPortfolio/Public/CustomAIController.h)
    * [`ACustomAIController.cpp`](Source/NewPortfolio/Private/CustomAIController.cpp)
    * [`BTTask_FindRandomPatrolLocation.cpp`](Source/NewPortfolio/Private/BTTask_FindRandomPatrolLocation.cpp)
    * [`BTTask_ChangeSpeed.cpp`](Source/NewPortfolio/Private/BTTask_ChangeSpeed.cpp)
    * [`BTTask_Attack.cpp`](Source/NewPortfolio/Private/BTTask_Attack.cpp)

* **Funcionalidades:**
    * `AIController` customizado em C++ como o "cérebro" da IA.
    * Detecção de jogador otimizada com `AIPerceptionComponent` (Visão e Audição).
    * Lógica modular com `Behavior Tree` e `Blackboard`.
    * `BTTasks` customizadas em C++ para ações como encontrar pontos de patrulha válidos na NavMesh e alterar a velocidade.
    * Altamente configurável no editor, usando variáveis `FName` para as chaves do Blackboard para evitar texto hard-coded.

### 2. Sistema de Interação Modular
Um componente de interação flexível e orientado a eventos. Ele permite que qualquer personagem interaja com qualquer objeto no mundo através de uma Interface C++, usando `Delegates` para uma comunicação limpa com a UI e outros sistemas.

* **Principais Arquivos de Código:**
    * [`UInteractionComponent.h`](Source/NewPortfolio/Public/InteractionComponent.h)
    * [`UInteractionComponent.cpp`](Source/NewPortfolio/Private/InteractionComponent.cpp)
    * [`BaseInteractableActor.h`](Source/NewPortfolio/Public/BaseInteractableActor.h)
    * [`BaseInteractableActor.cpp`](Source/NewPortfolio/Private/BaseInteractableActor.cpp)
    * (Requer que uma `InteractionInterface` seja implementada nos Actors que não são filhos da classe BaseInteractableItem.)*

* **Funcionalidades:**
    * **Baseado em Componente:** Adicione o componente a qualquer ator para dar a ele capacidades de interação.
    * **Orientado por Delegates:** Usa `Delegates` para transmitir mudanças de foco, desacoplando o sistema da UI.
    * **Performático:** Usa um `Timer` em vez do `Tick` para a detecção de foco.
    * **Flexível:** Funciona com qualquer ator que implemente a interface C++ ou Blueprint necessária.

### 3. Componente de Sprint e Stamina
Um Componente de Ator plug-and-play que adiciona uma mecânica completa de stamina e corrida a qualquer personagem. Todos os parâmetros são expostos para Blueprints para ajustes rápidos por designers.

* **Principais Arquivos de Código:**
    * [`UStaminaComponent.h`](Source/NewPortfolio/Public/StaminaComponent.h)
    * [`UStaminaComponent.cpp`](Source/NewPortfolio/Private/StaminaComponent.cpp)

* **Funcionalidades:**
    * Escrito em C++ para máxima performance.
    * Design plug-and-play.
    * Todas as variáveis (`MaxStamina`, `RegenRate`, `SprintSpeed`, etc.) são expostas para Blueprints para iteração rápida.
 
### 4. Componente de Vida
Um Actor Component também Plug-and-Play que implementa um sistema modular e completo de vida em qualquer ator ou personagem. Todas as funções, variáveis e parâmetros são expostos para blueprint para, além de ajudar nos ajustes rápidos por designers, também implementar lógicas customizadas via Blueprint, se for da preferência do usuário.

* **Principais Arquivos de Código:**
    * [`UHealthComponent.h`](Source/NewPortfolio/Public/HealthComponent.h)
    * [`UHealthComponent.cpp`](Source/NewPortfolio/Private/HealthComponent.cpp)
    * [`UHealthInterface.h`](Source/NewPortfolio/Public/HealthInterface.h)
    * [`UHealthInterface.cpp`](Source/NewPortfolio/Private/HealthInterface.cpp)

* **Funcionalidades:**
    * Escrito inteiramente em C++ para máxima performance.
    * Plug-and-play design.
    * Todas as variáveis (`MaxHealth`, `MinHealth`, `IsDead`, etc.) são expostas para blueprint para fácil iteração.
    * As funções (`Die()`, `HealPlayer()`, `DamagePlayer()`, etc.) estão todas expostas para blueprints também.
 
  ### 5. Inventory Component
Um Actor Component Plug-And-Play que adiciona um sistema de inventário completo e modular para qualquer ator que você quiser. Todas as funções, eventos e parâmetros são expostos para Blueprint para, além de rápida iteração por designers, ajudam também a montar a lógica dividida entre Blueprint/C++.

* **Principais Arquivos de Código:**
    * [`UInventoryComponent.h`](Source/NewPortfolio/Public/InventoryComponent.h)
    * [`UInventoryComponent.cpp`](Source/NewPortfolio/Private/InventoryComponent.cpp)
    * [`UInventoryInterface.h`](Source/NewPortfolio/Public/InventoryInterface.h)
    * [`UInventoryInterface.cpp`](Source/NewPortfolio/Private/InventoryInterface.cpp)
    * [`UItemType.h`](Source/NewPortfolio/Public/ItemType.h)
    * [`UItemType.cpp`](Source/NewPortfolio/Private/ItemType.cpp)
    * [`UInventoryDataAsset.h`](Source/NewPortfolio/Public/InventoryDataAsset.h)
    * [`UInventoryDataAsset.cpp`](Source/NewPortfolio/Private/InventoryDataAsset.cpp)

 
  * **Funcionalidades:**
    * Escrito em C++.
    * Fácil adição ao seu Player.
    * Variáveis e funções expostas para Blueprints.
    * Comunicação leve e performática. Não há `CASTING` direto. A comunicação é feita via `Interfaces`.
    * A maioria dos eventos podem ser alterados nas Blueprints por funções criadas por mim em C++.

---

## Como Usar Este Repositório

Este é um projeto Unreal Engine completo e funcional que serve como uma vitrine para os sistemas acima.
1.  Clone o repositório.
2.  Gere os arquivos de projeto do Visual Studio.
3.  Abra o arquivo `.uproject` e explore o mapa de demonstração.

Para migrar um componente para o seu próprio projeto, você precisaria copiar os arquivos de código relevantes (`.h` e `.cpp`) e garantir que quaisquer dependências de módulo necessárias (como `AIModule` ou `NavigationSystem`) sejam adicionadas ao arquivo `.Build.cs` do seu projeto.

</details>
