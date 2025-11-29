# Software Engineering (Bilingual) Review Reference: Chapters 6-7
## Overview
This review covers core knowledge of **Chapter 6 (Architectural Design)** and **Chapter 7 (Design and Implementation)**, aligned with the third assignment’s key exam points (true/false, fill-in-the-blank, multiple choice, single choice). Core content is presented in English with bilingual annotations for key terms to match the bilingual course requirements.

## Chapter 6: Architectural Design
### Core Knowledge Points (English + Bilingual Key Terms)
#### 1. Basic Concepts
- **Architectural Abstraction (体系结构抽象)**:
  - Architecture in the small (小体系结构): Focuses on decomposing individual programs into components.
  - Architecture in the large (大体系结构): Focuses on complex enterprise systems (distributed across multiple computers/companies).
- **Architectural Design Decisions (体系结构设计决策)**:
  - No formulaic design process (无公式化流程) – the process depends on system type, the architect’s experience, and specific requirements (not a fixed sequence of activities).
  - The choice of architectural style/structure relies on **non-functional requirements (非功能需求)** (e.g., performance, security, maintainability), not functional requirements.
  - Refactoring system architecture is expensive (重构体系结构成本高) (requires modifying most components); refactoring individual components is relatively easy.
- **Architectural Views (体系结构视图)**:
  - Krutchen’s 4+1 view model (core 4 views linked by use cases/scenarios):
    - Logical view (逻辑视图): Key abstractions (objects/classes) in the system.
    - Process view (进程视图): Runtime interacting processes (for analyzing non-functional characteristics like performance).
    - Development view (开发视图): Software decomposition for development (used by programmers/managers).
    - Physical view (物理视图): Hardware distribution of software components (for system deployment planning).
- **Architectural Patterns (体系结构模式)**:
  | Pattern Name                | Core Purpose                                                 | Typical Application Scenario                                 |
  | --------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | MVC (Model-View-Controller) | Separate presentation/interaction from system data (分离展示/交互与数据) | Web-based systems (multiple ways to view/interact with data) |
  | Layered                     | Organize functionality into layers (each layer relies on the layer below) | Systems requiring multi-level security or incremental development |
  | Repository                  | Central data repository for component interaction (components interact via repository) | Data-intensive systems (e.g., IDE, medical records systems)  |
  | Client-Server               | System as "services (servers) + service users (clients)"     | Distributed systems (e.g., shared database access from multiple locations) |
  | Pipe and Filter             | Data flows between "filters" (each filter = one type of data transformation) | Data-processing systems (batch/transaction-based)            |

### Corresponding Assignment Exam Points
| Question Type     | Typical Topics & Examples                                    |
| ----------------- | ------------------------------------------------------------ |
| True/False        | - "Refactoring components is easy; refactoring architecture is expensive" (True)<br>- "There is a formulaic architectural design process" (False)<br>- "Architectural style choice depends on functional requirements" (False) |
| Fill-in-the-Blank | - Two levels of architectural abstraction: [Architecture in the large/大体系结构] |
| Multiple Choice   | - Krutchen’s 4+1 view model (All correct: A: Logical view; B: Process view; C: Development view; D: Physical view) |
| Single Choice     | - Separate presentation/interaction from system data → MVC pattern (A)<br>- Data flows between transformation components → Pipe and Filter pattern (D)<br>- System as services (servers) + clients → Client-Server pattern (B) |

## Chapter 7: Design and Implementation
### Core Knowledge Points (English + Bilingual Key Terms)
#### 1. Basic Concepts
- **Design & Implementation Fundamentals**:
  - Core goal: Develop an **executable (可执行) software system** (the output of design/implementation stage).
  - "Build or Buy" strategy: Off-the-shelf systems can be adapted and **tailored (剪裁)** to user requirements (cheaper/faster than building from scratch).
- **Object-Oriented Design (OOD, 面向对象设计)**:
  - Object composition: Objects include both **data + operations (操作)** (core OOD concept; operations manipulate data).
  - System Context & Boundaries (系统上下文与边界): Understanding the system’s context helps define **boundaries (边界)** (distinguish features implemented in the system vs. external systems).
  - Object Identification: Map real-world entities to objects (rule of thumb: nouns = objects/attributes, verbs = operations; e.g., "Flight CA1842 arrived" → Object: Flight, Attribute: CA1842, Operation: arrived).
  - UML Design Models (3 key types):
    - Subsystem models (子系统模型): Static model (package diagram) – logical grouping of objects.
    - Sequence models (顺序模型): Dynamic model (sequence diagram) – order of object interactions (read top-to-bottom; use "alt" for conditional branches).
    - State machine models (状态机模型): Dynamic model (state diagram) – object state changes in response to events (e.g., weather station’s "Shutdown" → "Running" via `restart()`).
  - Interface Specification (接口规格说明):
    - Interfaces enable parallel design of objects/subsystems.
    - UML interface notation: No attribute section, include `«interface»` stereotype.
    - No simple 1:1 relationship between objects and interfaces (one object may have multiple interfaces; one interface may access multiple objects).
- **Design Patterns (设计模式)**:
  - Closely associated with object-oriented design (OO design) (key true/false point).
  - Gang of Four (GoF) 4 essential elements:
    1. Name (meaningful label for the pattern).
    2. Problem description (scenarios where the pattern applies).
    3. Solution description (components, relationships, responsibilities of the design).
    4. Consequences (results/trade-offs of applying the pattern).
- **Implementation Issues**:
  - Host-target development: Develop software on a **host system (宿主机)**, execute it on a separate **target system (目标机)** (core fill-in-the-blank term).

### Corresponding Assignment Exam Points
| Question Type     | Typical Topics & Examples                                    |
| ----------------- | ------------------------------------------------------------ |
| True/False        | - "Design patterns are usually associated with object-oriented design" (True) |
| Fill-in-the-Blank | - Design/implementation goal: [executable/可执行]<br>- Adapt off-the-shelf systems: [tailored/剪裁]<br>- Object composition: [operations/操作]<br>- System context outcome: [boundaries/边界]<br>- Implementation environment: [target/目标] |
| Multiple Choice   | - 1:1 relationship in weather station context model (A: Weather station ↔ Control system)<br>- States directly entering "Running" (weather station state diagram: A: Shutdown, B: Configuring)<br>- GoF 4 elements of design patterns (All correct: A: Name; B: Problem description; C: Solution description; D: Consequences) |
| Single Choice     | - Object identification for "Flight CA1842 arrived" → C (Object: Flight, Attribute: CA1842, Operation: arrived)<br>- Sequence diagram logic (weather station) → D (Correct order: request(report)→get(summary)→send(report)→reply(report))<br>- False interface statement → D (There is a simple 1:1 relationship between objects and interfaces) |

## Key Review Suggestions
1. **Architectural Patterns**: Memorize the core purpose of each pattern (MVC/Pipe and Filter/Client-Server) – this is the focus of single-choice questions.
2. **4+1 View Model**: Remember the 4 core views (Logical/Process/Development/Physical) for multiple-choice questions.
3. **OOD Basics**: Master object composition (data + operations) and object identification rules (noun = object/attribute, verb = operation).
4. **Design Patterns**: Focus on GoF 4 elements and the link between patterns and OOD.
5. **Interface Specification**: Highlight the "no 1:1 object-interface relationship" (key single-choice trap).
6. **UML Models**: Understand sequence/state diagram logic (e.g., reading order, state transitions) – frequent exam points for single/multiple choice.