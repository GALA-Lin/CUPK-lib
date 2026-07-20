# Software Engineering (Bilingual) Review Reference: Chapters 6-7
软件工程（双语）复习参考：第六章-第七章

## Overview
概述

This review covers core knowledge of **Chapter 6 (Architectural Design)** and **Chapter 7 (Design and Implementation)**, aligned with the third assignment’s key exam points (true/false, fill-in-the-blank, multiple choice, single choice). Core content is presented in English with bilingual annotations for key terms to match the bilingual course requirements.
本次复习涵盖第六章（架构设计）和第七章（设计与实现）的核心知识，与第三次作业的关键考试要点（判断题、填空题、选择题、单选题）相一致。核心内容以英文呈现，关键术语附有双语注释，以满足双语课程要求。

## Chapter 6: Architectural Design
第六章：架构设计

### Core Knowledge Points (English + Bilingual Key Terms)
核心知识点（英文+双语关键术语）

#### 1\. Basic Concepts
1\. 基本概念

*   **Architectural Abstraction (体系结构抽象)**:
    体系结构抽象 (Architectural Abstraction):
    *   Architecture in the small (小体系结构): Focuses on decomposing individual programs into components.
        小体系结构 (Architecture in the small): 关注将单个程序分解成组件。
    *   Architecture in the large (大体系结构): Focuses on complex enterprise systems (distributed across multiple computers/companies).
        大体系结构：关注复杂的企事业系统（分布在多台计算机/公司中）。
*   **Architectural Design Decisions (体系结构设计决策)**:
    体系结构设计决策：
    *   No formulaic design process (无公式化流程) – the process depends on system type, the architect’s experience, and specific requirements (not a fixed sequence of activities).
        无公式化流程——流程取决于系统类型、架构师的经验和具体需求（不是一系列固定的活动顺序）。
    *   The choice of architectural style/structure relies on **non-functional requirements (非功能需求)** (e.g., performance, security, maintainability), not functional requirements.
        选择体系结构风格/结构依赖于非功能需求（例如，性能、安全性、可维护性），而非功能需求。
    *   Refactoring system architecture is expensive (重构体系结构成本高) (requires modifying most components); refactoring individual components is relatively easy.
        重构体系结构成本高（需要修改大多数组件）；重构单个组件相对容易。
*   **Architectural Views (体系结构视图)**:
    体系结构视图：
    *   Krutchen’s 4+1 view model (core 4 views linked by use cases/scenarios):
        Krutchen 的 4+1 视图模型（核心 4 个视图通过用例/场景链接）：
        *   **Logical view**: The logical view is concerned with the functionality that the system provides to end-users. [UML diagrams](https://en.wikipedia.org/wiki/Unified_Modeling_Language) are used to represent the logical view, and include [class diagrams](https://en.wikipedia.org/wiki/Class_diagram), and [state diagrams](https://en.wikipedia.org/wiki/State_diagram).(https://en.wikipedia.org/wiki/4%2B1_architectural_view_model#cite_note-Kontio05-2)
            逻辑视图：逻辑视图关注系统向最终用户提供的功能。使用 UML 图来表示逻辑视图，包括类图和状态图。 (https://en.wikipedia.org/wiki/4%2B1_architectural_view_model#cite_note-Kontio05-2)
        *   **Process view**: The process view deals with the dynamic aspects of the system, explains the system processes and how they communicate, and focuses on the run time behavior of the system. The process view addresses concurrency, distribution, integrator, performance, and scalability, etc. UML diagrams to represent process view include the [sequence diagram](https://en.wikipedia.org/wiki/Sequence_diagram), [communication diagram](https://en.wikipedia.org/wiki/Communication_diagram), [activity diagram](https://en.wikipedia.org/wiki/Activity_diagram).(https://en.wikipedia.org/wiki/4%2B1_architectural_view_model#cite_note-3)[(https://en.wikipedia.org/wiki/4%2B1_architectural_view_model#cite_note-Kontio05-2)
            过程视图：过程视图处理系统的动态方面，解释系统进程及其通信方式，并关注系统的运行时行为。过程视图涉及并发性、分布式、集成器、性能和可扩展性等。用于表示过程视图的 UML 图包括时序图、通信图和活动图。 (https://en.wikipedia.org/wiki/4%2B1_architectural_view_model#cite_note-3) (https://en.wikipedia.org/wiki/4%2B1_architectural_view_model#cite_note-Kontio05-2)
        *   **Development view**: The development view (aka the *implementation view*) illustrates a system from a programmer's perspective and is concerned with software management. UML Diagrams used to represent the development view include the [Package diagram](https://en.wikipedia.org/wiki/Package_diagram) and the [Component diagram](https://en.wikipedia.org/wiki/Component_diagram).(https://en.wikipedia.org/wiki/4%2B1_architectural_view_model#cite_note-Kontio05-2)
            开发视图：开发视图（也称为实现视图）从程序员的视角展示系统，并关注软件管理。用于表示开发视图的 UML 图包括包图和组件图。 (https://en.wikipedia.org/wiki/4%2B1_architectural_view_model#cite_note-Kontio05-2)
        *   **Physical view**: The physical view (aka the *deployment view*) depicts the system from a system engineer's point of view. It is concerned with the topology of software components on the physical layer as well as the physical connections between these components. UML diagrams used to represent the physical view include the [deployment diagram](https://en.wikipedia.org/wiki/Deployment_diagram).(https://en.wikipedia.org/wiki/4%2B1_architectural_view_model#cite_note-Kontio05-2)
            物理视图：物理视图（也称为部署视图）从系统工程师的角度描绘系统。它关注物理层上软件组件的拓扑结构以及这些组件之间的物理连接。用于表示物理视图的 UML 图包括部署图。 (https://en.wikipedia.org/wiki/4%2B1_architectural_view_model#cite_note-Kontio05-2)
        *   **Scenarios**: The description of an architecture is illustrated using a small set of **[use cases](https://en.wikipedia.org/wiki/Use_case), or scenarios**, which become a fifth view. The scenarios describe sequences of interactions between objects and between processes. They are used to identify architectural elements and to illustrate and validate the architecture design. They also serve as a starting point for tests of an architecture prototype. This view is also known as the **use case view**.
            场景：通过使用一组用例，或称为场景，来描述架构，这些场景成为第五个视图。场景描述了对象之间以及进程之间的交互序列。它们用于识别架构元素，并说明和验证架构设计。它们还作为架构原型测试的起点。这个视图也称为用例视图。
*   **Architectural Patterns (体系结构模式)**:
    体系结构模式（体系结构模式）：
    
    | Pattern Name模式名称 | Core Purpose核心目的 | Typical Application Scenario典型应用场景 |
    | --- | --- | --- |
    | MVC (Model-View-Controller)MVC（模型-视图-控制器） | Separate presentation/interaction from system data (分离展示/交互与数据) | Web-based systems (multiple ways to view/interact with data) |
    | Layered  分层 | Organize functionality into layers (each layer relies on the layer below)将功能组织到层中（每一层都依赖于下面的层） | Systems requiring multi-level security or incremental development需要多级安全或增量开发的系统 |
    | Repository仓库 | Central data repository for component interaction (components interact via repository)组件交互的中央数据仓库（组件通过仓库进行交互） | Data-intensive systems (e.g., IDE, medical records systems)数据密集型系统（例如 IDE、医疗记录系统） |
    | Client-Server客户端-服务器 | System as "services (servers) + service users (clients)"系统作为"服务（服务器）+服务用户（客户端）" | Distributed systems (e.g., shared database access from multiple locations)分布式系统（例如，从多个位置共享数据库访问） |
    | Pipe and Filter管道和过滤器 | Data flows between "filters" (each filter = one type of data transformation)数据在"过滤器"之间流动（每个过滤器=一种数据转换） | Data-processing systems (batch/transaction-based)数据处理系统（批处理/事务型） |
    

### Corresponding Assignment Exam Points
相应的作业考试分数

| Question Type问题类型 | Typical Topics & Examples典型主题与示例 |
| --- | --- |
| True/False判断题 | \- "Refactoring components is easy; refactoring architecture is expensive" (True)- "重构组件容易；重构架构昂贵"（正确）- "There is a formulaic architectural design process" (False)- "存在一个公式化的架构设计过程"（错误）- "Architectural style choice depends on functional requirements" (False)- "架构风格的选择取决于功能需求"（错误） |
| Fill-in-the-Blank填空题 | \- Two levels of architectural abstraction: \[Architecture in the large/大体系结构\]- 两种架构抽象层次：\[大体系结构\] |
| Multiple Choice选择题 | \- Krutchen’s 4+1 view model (All correct: A: Logical view; B: Process view; C: Development view; D: Physical view)- Krutchen 的 4+1 视图模型（全部正确：A：逻辑视图；B：过程视图；C：开发视图；D：物理视图） |
| Single Choice单选题 | \- Separate presentation/interaction from system data → MVC pattern (A)- 将展示/交互与系统数据分离 → MVC 模式（A）- Data flows between transformation components → Pipe and Filter pattern (D)- 数据在转换组件之间流动 → 管道和过滤器模式（D）- System as services (servers) + clients → Client-Server pattern (B)- 系统作为服务（服务器）+ 客户端 → 客户端-服务器模式（B） |

## Chapter 7: Design and Implementation
第 7 章：设计与实现

### Core Knowledge Points (English + Bilingual Key Terms)
核心知识点（英文+双语关键术语）

#### 1\. Basic Concepts
1\. 基本概念

*   **Design & Implementation Fundamentals**:
    设计与实现基础：
    *   Core goal: Develop an **executable (可执行) software system** (the output of design/implementation stage).
        核心目标：开发一个可执行的软件系统（设计/实现阶段的结果）。
    *   "Build or Buy" strategy: Off-the-shelf systems can be adapted and **tailored (剪裁)** to user requirements (cheaper/faster than building from scratch).
        "构建或购买"策略：现成系统可以适应和定制（剪裁）以满足用户需求（比从头构建更便宜/更快）。
*   **Object-Oriented Design (OOD, 面向对象设计)**:
    面向对象设计（OOD，面向对象设计）：
    *   Object composition: Objects include both **data + operations (操作)** (core OOD concept; operations manipulate data). 
    *   System Context & Boundaries (系统上下文与边界): Understanding the system’s context helps define **boundaries (边界)** (distinguish features implemented in the system vs. external systems). 
    *   Object Identification: Map real-world entities to objects (rule of thumb: nouns = objects/attributes, verbs = operations; e.g., "Flight CA1842 arrived" → Object: Flight, Attribute: CA1842, Operation: arrived). 
    *   UML Design Models (3 key types):  
        *   Subsystem models (子系统模型): Static model (package diagram) – logical grouping of objects.
            子系统模型（子系统模型）：静态模型（包图）——对象的逻辑分组。
        *   Sequence models (顺序模型): Dynamic model (sequence diagram) – order of object interactions (read top-to-bottom; use "alt" for conditional branches).
            顺序模型（顺序模型）：动态模型（时序图）——对象交互的顺序（从上到下阅读；使用"alt"表示条件分支）。
        *   State machine models (状态机模型): Dynamic model (state diagram) – object state changes in response to events (e.g., weather station’s "Shutdown" → "Running" via `restart()`).
            状态机模型（状态机模型）：动态模型（状态图）——对象在事件响应下的状态变化（例如，气象站的"关闭"→"运行"通过 `restart()` ）。
    *   Interface Specification (接口规格说明):
        接口规格说明（接口规格说明）：
        *   Interfaces enable parallel design of objects/subsystems.
            接口支持对象/子系统的并行设计。
        *   UML interface notation: No attribute section, include `«interface»` stereotype.
            UML 接口符号：无属性部分，包含 `«interface»` 模板化。
        *   No simple 1:1 relationship between objects and interfaces (one object may have multiple interfaces; one interface may access multiple objects).
            对象和接口之间没有简单的 1:1 关系（一个对象可以有多个接口；一个接口可以访问多个对象）。
*   **Design Patterns (设计模式)**:
    设计模式（Design Patterns）：
    *   Closely associated with object-oriented design (OO design) (key true/false point).
        与面向对象设计（OO 设计）密切相关（关键真伪点）。
    *   Gang of Four (GoF) 4 essential elements:
        四人帮（GoF）4 个基本要素：
        1.  Name (meaningful label for the pattern).
            名称（模式的具有意义的标签）。
        2.  Problem description (scenarios where the pattern applies).
            问题描述（模式适用的场景）。
        3.  Solution description (components, relationships, responsibilities of the design).
            解决方案描述（组件、关系、设计职责）。
        4.  Consequences (results/trade-offs of applying the pattern).
            后果（应用模式的成果/权衡）。
*   **Implementation Issues**:
    实施问题：
    *   Host-target development: Develop software on a **host system (宿主机)**, execute it on a separate **target system (目标机)** (core fill-in-the-blank term).
        宿主机-目标机开发：在宿主机上开发软件，在独立的目标机上执行（核心填空术语）。

### Corresponding Assignment Exam Points
对应的作业考试分数

| Question Type题型 | Typical Topics & Examples典型主题与示例 |
| --- | --- |
| True/False判断题 | \- "Design patterns are usually associated with object-oriented design" (True) |
| Fill-in-the-Blank | \- Design/implementation goal: \[executable/可执行\] - Adapt off-the-shelf systems: \[tailored/剪裁\] - Object composition: \[operations/操作\]- 对象组合：\[operations/操作\]- System context outcome: \[boundaries/边界\]- 系统上下文结果：\[boundaries/边界\]- Implementation environment: \[target/目标\]- 实现环境：\[target/目标\] |
| Multiple Choice选择题 | \- 1:1 relationship in weather station context model (A: Weather station ↔ Control system) - States directly entering "Running" (weather station state diagram: A: Shutdown, B: Configuring) - GoF 4 elements of design patterns (All correct: A: Name; B: Problem description; C: Solution description; D: Consequences) |
| Single Choice | \- Object identification for "Flight CA1842 arrived" → C (Object: Flight, Attribute: CA1842, Operation: arrived) - Sequence diagram logic (weather station) → D (Correct order: request(report)→get(summary)→send(report)→reply(report)) - False interface statement → D (There is a simple 1:1 relationship between objects and interfaces) |

## Key Review Suggestions 

1.  **Architectural Patterns**: Memorize the core purpose of each pattern (MVC/Pipe and Filter/Client-Server) – this is the focus of single-choice questions. 
2.  **4+1 View Model**: Remember the 4 core views (Logical/Process/Development/Physical) for multiple-choice questions. 
3.  **OOD Basics**: Master object composition (data + operations) and object identification rules (noun = object/attribute, verb = operation). 
4.  **Design Patterns**: Focus on GoF 4 elements and the link between patterns and OOD. 
5.  **Interface Specification**: Highlight the "no 1:1 object-interface relationship" (key single-choice trap).
    接口规范：强调“非 1:1 对象-接口关系”（关键单选陷阱）。
6.  **UML Models**: Understand sequence/state diagram logic (e.g., reading order, state transitions) – frequent exam points for single/multiple choice.
    UML 模型：理解时序/状态图逻辑（例如，读取顺序、状态转换）——单选/多选题的常见考点。