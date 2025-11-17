# Software Engineering (Bilingual) Review Reference: Chapter 1-2
软件工程（双语）评审参考：第一章-第二章

## Overview
概述

This review covers core knowledge from Chapter 1 (Introduction) and Chapter 2 (Software Processes), aligned with assignment questions (true/false, fill-in-the-blank, multiple choice, single choice) and key exam points. All key content is presented in English (bilingual hints where necessary for clarity).
本综述涵盖第一章（引言）和第二章（软件过程）的核心知识，与作业问题（判断题、填空题、选择题、单选题）和考试重点相一致。所有关键内容均以英文呈现（必要时提供双语提示以确保清晰）。

## Chapter 1: Introduction
第一章：引言

### Key Knowledge Points (English)
关键知识点（英文）

*   **Definition of Software Engineering (SE)**: An engineering discipline concerned with all aspects of software production (from specification to maintenance).
    软件工程（SE）的定义：一个关注软件生产所有方面的工程学科（从规范到维护）。
*   **Software Product Types**:
    软件产品类型：
    *   Generic products: Stand-alone systems for general markets (specification owned by developers).
        通用产品：面向一般市场的独立系统（规范由开发者拥有）。
    *   Customized products: Commissioned for specific customers (specification owned by customers).
        定制产品：为特定客户定制（规范由客户拥有）。
*   **Fundamental SE Activities**: Specification → Design & Development → Validation → Evolution/Maintenance.
    基础软件工程活动：规格→设计开发→验证→演进/维护。
*   **Software Failure Causes**: Increasing system complexity; failure to adopt software engineering methods.
    软件故障原因：系统复杂性增加；未能采用软件工程方法。
*   **General Issues Affecting Software**: Heterogeneity, business & social change, security & trust, scale.
    影响软件的普遍问题：异构性、商业与社会变革、安全与信任、规模。
*   **Professional Software Components**: Programs, associated documentation, libraries, configuration data (all four are required).
    专业软件组件：程序、相关文档、库、配置数据（所有四项都是必需的）。
*   **Application Types**: Data collection systems (e.g., wilderness weather station), embedded control systems, batch processing systems, etc.
    应用类型：数据收集系统（例如，野外气象站）、嵌入式控制系统、批量处理系统等。
*   **Web-based SE Features**: Conventional SE fundamentals still apply; software reuse and incremental development are dominant approaches.
    基于网络的软件工程特征：传统的软件工程基础仍然适用；软件复用和增量开发是主要方法。
*   **Professional Responsibilities**: Confidentiality, competence, intellectual property rights, computer misuse.
    专业责任：保密性、能力、知识产权、计算机滥用。

### Corresponding Assignment Exam Points
相应的作业考试分数

| Question Type问题类型 | Typical Topics & Examples典型主题与示例 |
| --- | --- |
| True/False判断题 | \- "Universal SE notations/methods exist" (False)- "通用软件工程符号/方法存在"（错误）- "SE supports individual programming" (False)- "软件工程支持个人编程"（错误）- "SE focuses solely on design/implementation" (False)- "软件工程仅关注设计/实现"（错误） |
| Fill-in-the-Blank填空题 | \- Software failure factors: \[software engineering/SE/软件工程\]- 软件故障因素：\[软件工程/SE/软件工程\]- SE activities: \[software evolution/software maintenance/软件演化/维护\]- 软件工程活动：\[软件演化/维护\]- Customized product spec owner: \[customer/客户\]- 定制产品规格负责人：\[客户\]- General issue affecting software: \[scale/规模\]- 影响软件的普遍问题：\[规模\]- Professional responsibility: \[competence/工作能力\]- 专业责任：\[工作能力\] |
| Multiple Choice选择题 | \- Components of professional software (A: programs; B: documentation; C: libraries; D: configuration data)- 专业软件的组成部分（A：程序；B：文档；C：库；D：配置数据） |
| Single Choice单选题 | \- Key factor for SE methods (B: Type of application being developed)- SE 方法的关键因素（B：正在开发的应用类型）- False statement about Web-based SE (C: Conventional SE ideas no longer apply)- 关于基于 Web 的软件工程的错误说法（C：传统的软件工程思想不再适用）- Application type of wilderness weather station (A: Data collection systems)- 野外气象站的应用类型（A：数据收集系统） |

## Chapter 2: Software Processes
第 2 章：软件过程

### Key Knowledge Points (English)
关键知识点（英文）

*   **Software Process Models**:
    软件过程模型：
    *   Waterfall model: Plan-driven, sequential phases (requirements → design → implementation → testing → maintenance); suitable for stable requirements/large engineering projects.
        瀑布模型：计划驱动、顺序阶段（需求→设计→实现→测试→维护）；适用于稳定需求/大型工程项目。
    *   Incremental development: Interleaved specification/development/validation; feedback-driven; benefits include reduced change costs and rapid delivery.
        增量开发：交织规范/开发/验证；反馈驱动；优点包括降低变更成本和快速交付。
    *   Integration & configuration: Reuse-based (existing components + integrating framework); standard for business systems.
        集成与配置：基于复用（现有组件+集成框架）；商业系统的标准。
*   **Process Description Components**: Activities, ordering of activities, products, roles, pre-conditions, post-conditions.
    过程描述组件：活动、活动顺序、产品、角色、前提条件、后置条件。
*   **Requirements Engineering**: Process of defining services/constraints; outputs an agreed requirements document.
    需求工程：定义服务/约束的过程；输出一个双方同意的需求文档。
*   **Design & Implementation**: Converts specification to executable system; debugging = finding + correcting program faults.
    设计与实现：将规范转换为可执行系统；调试=发现+纠正程序错误。
*   **Software Validation (V&V)**:
    软件验证（V&V）：
    *   Testing is the most common V&V activity.
        测试是最常见的 V&V 活动。
    *   3-stage testing: Component testing → System testing → Customer/Beta testing (beta testing: selected users try software).
        三阶段测试：组件测试→系统测试→客户/ Beta 测试（Beta 测试：选定用户试用软件）。
*   **Coping with Change**:
    应对变化：
    *   Change anticipation (e.g., prototyping) + Change tolerance (e.g., incremental delivery).
        变化预期（例如，原型设计）+ 变化容忍度（例如，增量交付）。
    *   Refactoring: Improves program structure to prevent degradation.
        重构：改进程序结构以防止退化。
*   **Process Improvement**:
    流程改进：
    *   Process maturity approach (SEI 5 levels: Initial → Managed → Defined → Quantitatively managed → Optimizing).
        流程成熟度方法（SEI 5 级：初始 → 受控 → 定义 → 定量管理 → 优化）。
    *   Agile approach: Iterative, low-overhead, responsive to changes.
        敏捷方法：迭代、低开销、响应变化。

### Corresponding Assignment Exam Points
相应的作业考试分数

| Question Type问题类型 | Typical Topics & Examples典型主题与示例 |
| --- | --- |
| True/False判断题 | \- "Development & maintenance are separate processes" (False)- "开发与维护是分离的过程"（错误）- "High-priority requirements in early increments get most testing" (False)- "早期增量中的高优先级需求得到最多测试"（错误） |
| Fill-in-the-Blank填空题 | \- Process activity element: \[ordering/次序\]- 处理活动元素：\[次序\]- Process model: \[Integration and configuration/集成和配置\]- 处理模型：\[集成和配置\]- Debugging: \[Debugging/调试\]- 调试：\[调试\]- Core V&V activity: \[testing/system testing/测试\]- 核心 V&V 活动：\[测试\]- 3-stage testing: \[System testing/系统测试\]- 三阶段测试：\[系统测试\]- Change tolerance method: \[Change tolerance/变更容忍\]- 变更容忍方法：\[变更容忍\]- Coping with change: \[Incremental delivery/增量式交付\]- 应对变更：\[增量式交付\]- Improve program structure: \[Refactoring/重构\]- 改进程序结构：\[重构\]- Process improvement approach: \[agile/敏捷\]- 流程改进方法：\[敏捷\]- SEI maturity cycle: \[analyze/分析\]- SEI 成熟度周期：\[分析\]- SEI maturity level: \[Managed/被管理级\]- SEI 成熟度级别：\[被管理级\] |
| Multiple Choice选择题 | \- Waterfall model applicable scenarios (A: Stable requirements; B: Limited changes; D: Large multi-site projects)- 滚动式模型适用场景（A：需求稳定；B：变更有限；D：大型多站点项目）- Incremental development benefits (A: Reduced change cost; B: Faster feedback; C: Rapid delivery)- 增量开发的优势（A：降低变更成本；B：更快反馈；C：快速交付）- Process description components (A: Pre-conditions; B: Products; C: Roles; D: Post-conditions)- 流程描述组件（A：前置条件；B：产品；C：角色；D：后置条件） |
| Single Choice单选题 | \- False about Integration & configuration (A: User requirements are fully satisfied)- 关于集成与配置的错误（A：用户需求完全满足）- False about software specification (B: Developers need high-level spec; users need detailed)- 关于软件规格的错误（B：开发者需要高层级规格；用户需要详细规格）- Incremental delivery unsuitable scenario (A: Replace existing system)- 增量交付不适用场景（A：替换现有系统）- Beta testing participants (D: Selected users)- Beta 测试参与者（D：选定用户） |

## Subjective Ideological & Political Question
主观意识形态与政治问题

*   **Focus**: EDA software (definition, importance); international leading EDA companies (Synopsys, Cadence, Siemens EDA); China’s gaps in EDA technology; related "chokepoint" events & reflections.
    重点：EDA 软件（定义、重要性）；国际领先 EDA 公司（Synopsys、Cadence、Siemens EDA）；中国 EDA 技术的差距；相关“卡脖子”事件与反思。
*   **Requirements**: ≥2000 words; original content (no direct copying); Word file with cover (name, class, student ID); structured formatting.
    要求：≥2000 字；原创内容（不得直接抄袭）；封面 Word 文档（姓名、班级、学号）；结构化格式。

## Review Suggestions
审阅建议

1.  Prioritize memorizing core terms and their definitions (e.g., SE activities, process models, testing stages).
    优先记忆核心术语及其定义（例如，SE 活动、过程模型、测试阶段）。
2.  Understand the applicability of each process model (when to use waterfall vs. incremental development).
    理解每种过程模型的应用场景（何时使用瀑布式开发与增量式开发）。
3.  Master fill-in-the-blank answers—focus on key nouns/verbs from the textbook and PPT.
    掌握填空题答案——重点关注教科书和 PPT 中的关键名词/动词。
4.  For the subjective question, collect data on EDA industry trends, Sino-US tech competition, and China’s independent innovation strategies.
    对于主观问题，收集关于 EDA 行业趋势、中美科技竞争以及中国自主创新战略的数据。

# 1\. English-Chinese Bilingual Glossary of Core Terms (Chapters 1-2)
1\. 英语-中文核心术语双语词汇表（第一章-第二章）

| Category类别 | English Term英文术语 | Chinese Term中文术语 | Key Notes (Relevance to Assignment)关键点（与作业的相关性） |
| --- | --- | --- | --- |
| Basic Concepts基本概念 | Software Engineering (SE)软件工程 (SE) | 软件工程 | 作业填空考点，软件失效的解决手段 |
|  | Professional Software专业软件 | 专业软件 | 多选题考点，包含程序、文档、库、配置数据 |
|  | Generic Products通用产品 | 通用产品 | 填空题考点，规格说明归开发者所有 |
|  | Customized Products定制产品 | 定制化产品 | 填空题考点，规格说明归客户所有 |
|  | Software Failure软件故障 | 软件失效 | 填空题考点，原因：系统复杂度+未使用软件工程方法 |
| Software Process Models软件过程模型 | Waterfall Model瀑布模型 | 瀑布模型 | 多选题/判断题考点，适用于需求稳定的场景 |
|  | Incremental Development增量开发 | 增量式开发 | 单选题/多选题考点，优势：降低变更成本、快速交付 |
|  | Integration and Configuration集成与配置 | 集成和配置 | 填空题考点，基于软件复用，是商业系统的标准方法 |
| Process Activities过程活动 | Software Specification软件规范 | 软件规格说明 | 单选题考点，定义系统服务和约束的过程 |
|  | Software Design and Implementation软件设计与实现 | 软件设计与实现 | 单选题考点，将规格说明转化为可执行系统 |
|  | Software Validation软件验证 | 软件确认 | 填空题考点，包含评审和测试，测试是最常用手段 |
|  | Software Evolution / Maintenance软件演化 / 维护 | 软件演化/维护 | 填空题考点，软件过程的核心活动之一 |
| Testing & Validation测试与验证 | Debugging调试 | 调试 | 填空题考点，定位并修正程序错误的活动 |
|  | Component Testing组件测试 | 组件测试 | 填空题考点，三阶段测试的第一阶段 |
|  | System Testing系统测试 | 系统测试 | 填空题考点，三阶段测试的第二阶段 |
|  | Customer / Beta Testing客户 / Beta 测试 | 客户测试/β测试 | 单选题考点，β测试由选定用户参与 |
| Change & Improvement变更与改进 | Change Anticipation变更预期 | 变化预见 | 填空题考点，通过原型等方式提前应对变更 |
|  | Change Tolerance公差 | 变化容忍 | 填空题考点，通过增量交付实现 |
|  | Refactoring重构 | 重构 | 填空题考点，优化程序结构以避免退化 |
|  | Process Maturity Approach过程成熟度方法 | 过程成熟度方法 | 填空题考点，SEI提出5级成熟度 |
|  | Agile Approach敏捷方法 | 敏捷方法 | 填空题考点，过程改进的两大途径之一，强调迭代和低开销 |
| Others其他 | Heterogeneity异构性 | 异构性 | 填空题考点，影响软件的四大通用问题之一 |
|  | Scale规模 | 规模 | 填空题考点，影响软件的四大通用问题之一 |
|  | Confidentiality保密性 | 保密（责任） | 填空题考点，软件工程师的职业责任之一 |
|  | Competence能力 | 工作能力（责任） | 填空题考点，软件工程师的职业责任之一 |

# 2\. Software Engineering (Chapters 1-2) Mock Test
2\. 软件工程（第一章-第二章）模拟测试

## Test Information
测试信息

*   Total Questions: 20 (10 True/False, 5 Fill-in-the-Blank, 3 Multiple Choice, 1 Single Choice, 1 Subjective Question)
    总题数：20 题（10 题判断题，5 题填空题，3 题选择题，1 题单选题，1 题简答题）
*   Total Score: 20 Points
    总分：20 分

### Part 1: True/False (1 point each, total 10 points)
第一部分：判断题（每题 1 分，共 10 分）

1.  Software engineering provides universal methods that are applicable to all types of software development. ( )
    软件工程提供适用于所有类型软件开发通用的方法。（ ）
2.  The specification of customized software products is owned by the software developer. ( )
    定制软件产品的规格由软件开发者拥有。（ ）
3.  Web-based software engineering no longer requires the fundamental principles of conventional software engineering. ( )
    基于网络的软件工程不再需要传统软件工程的基本原则。( )
4.  The waterfall model is most suitable for projects with unstable and frequently changing requirements. ( )
    瀑布模型最适用于需求不稳定且经常变化的项目。( )
5.  Incremental development allows customers to gain value from software earlier than the waterfall model. ( )
    增量开发使客户比瀑布模型更早地从软件中获得价值。( )
6.  Debugging is the same as testing, both focusing on finding program faults. ( )
    调试与测试相同，两者都专注于查找程序错误。( )
7.  Beta testing is usually conducted by the software development team to verify system functions. ( )
    Beta 测试通常由软件开发团队进行，以验证系统功能。( )
8.  Most software systems are completely new, so development and maintenance can be treated as separate processes. ( )
    大多数软件系统是完全新的，因此开发和维护可以视为分离的过程。( )
9.  Refactoring aims to improve the structure of a program without changing its external functions. ( )
    重构旨在在不改变程序外部功能的情况下改进程序结构。( )
10.  The "Optimizing" level is the highest level in the SEI process maturity model. ( )
    "优化"级别是 SEI 过程成熟度模型中的最高级别。( )

### Part 2: Fill-in-the-Blank (1 point each, total 5 points)
第二部分：填空题（每题 1 分，共 5 分）

1.  The four fundamental software engineering activities are software specification, software design and development, software validation, and \_\_\_\_\_\_\_\_\_\_\_\_\_\_ (软件演化/software evolution).
    软件工程的四个基本活动是软件规范、软件设计和开发、软件验证和 \_\_\_\_\_\_\_\_\_\_\_\_\_\_（软件演化）。
2.  The three core software process models introduced in the textbook are the waterfall model, incremental development, and \_\_\_\_\_\_\_\_\_\_\_\_\_\_ (集成和配置/Integration and configuration).
    教材中介绍的三种核心软件过程模型是瀑布模型、增量开发和 \_\_\_\_\_\_\_\_\_\_\_\_\_\_（集成和配置）。
3.  The three-stage testing process includes component testing, \_\_\_\_\_\_\_\_\_\_\_\_\_\_ (系统测试/System testing), and customer testing.
    三阶段测试过程包括组件测试、 \_\_\_\_\_\_\_\_\_\_\_\_\_\_（系统测试）和客户测试。
4.  The two approaches to coping with changing requirements are system prototyping and \_\_\_\_\_\_\_\_\_\_\_\_\_\_ (增量式交付/Incremental delivery).
    应对不断变化需求的两种方法是系统原型设计和（增量式交付）。
5.  The SEI process maturity model has five levels: Initial, \_\_\_\_\_\_\_\_\_\_\_\_\_\_ (被管理级/Managed), Defined, Quantitatively managed, and Optimizing.
    SEI 过程成熟度模型有五个级别：初始级、（被管理级）、定义级、定量管理级和优化级。

### Part 3: Multiple Choice (2 points each, partial score for incomplete selection, total 6 points)
第三部分：选择题（每题 2 分，部分选择得部分分数，总分 6 分）

1.  Which of the following belong to the components of professional software? ( )
    以下哪些属于专业软件的组成部分？（ ）
    A. Computer hardware
    A. 计算机硬件
    B. Associated documentation
    B. 相关文档
    C. Configuration data
    C. 配置数据
    D. Reusable libraries
    D. 可重用库
    
2.  Which of the following are the benefits of incremental development? ( )
    以下哪些是增量开发的好处？( )
    A. Reducing the cost of requirement changes
    A. 降低需求变更的成本
    B. Making it harder to obtain customer feedback
    B. 使获取客户反馈更加困难
    C. Delivering useful software more quickly
    C. 更快地交付有用软件
    D. Improving the visibility of the development process
    D. 提高开发过程的可见性
    
3.  Which of the following are included in software process descriptions? ( )
    以下哪些包含在软件过程描述中？ ( )
    A. Pre-conditions of activities
    A. 活动的先决条件
    B. Roles of participants
    B. 参与者的角色
    C. Outcomes of activities (products)
    C. 活动的成果（产品）
    D. Market share of the software
    D. 软件的市场份额
    

### Part 4: Single Choice (1 point each, total 1 point)
第四部分：单选题（每题 1 分，共 1 分）

1.  Which factor is the most significant in determining the choice of software engineering methods? ( )
    在确定软件工程方法选择时，哪个因素是最重要的？（ ）
    A. The number of developers in the team
    A. 团队中开发者的数量
    B. The type of application being developed
    B. 正在开发的应用类型
    C. The budget of the project
    C. 项目的预算
    D. The brand of development tools
    D. 开发工具的品牌

### Part 5: Subjective Ideological & Political Question (4 points)
第五部分：主观意识形态与政治问题（4 分）

In recent years, China has accelerated the independent research and development of key core technologies in the software field. Combined with the knowledge of software engineering and the background of "chokepoint" technologies (e.g., EDA, operating systems), answer the following questions:
近年来，中国在软件领域的关键核心技术自主研发方面加快了步伐。结合软件工程的知识和“卡脖子”技术（例如 EDA、操作系统）的背景，回答以下问题：
(1) What is the significance of independent innovation in software engineering for China’s digital economy?
（1）软件工程中的自主创新对中国数字经济有何意义？
(2) As a software engineering learner, what abilities should you develop to contribute to the independent research and development of core software technologies?
（2）作为一名软件工程学习者，你应该培养哪些能力来为关键软件技术的自主研发做出贡献？

# 3\. Mock Test Answer Key
3\. 模拟测试答案键

## Part 1: True/False
第一部分：判断题

1.  × (No universal methods; different software requires different approaches)
    ×（没有通用方法；不同软件需要不同方法）
2.  × (Customized products’ specification is owned by customers)
    ×（定制产品的规格由客户拥有）
3.  × (Conventional SE fundamentals still apply to web-based software)
    ×（传统软件工程基础仍然适用于基于网络的软件）
4.  × (Waterfall model is suitable for stable requirements)
    × (瀑布模型适用于稳定的需求)
5.  √ (Incremental delivery provides early usable software)
    √ (增量交付提供早期可用的软件)
6.  × (Debugging = finding + correcting faults; testing focuses on finding faults)
    × (调试=发现+纠正错误；测试侧重于发现错误)
7.  × (Beta testing is conducted by selected users, not developers)
    ×（Beta 测试由选定用户进行，而不是开发者）
8.  × (Development and maintenance are a continuum, not separate)
    × (开发和维护是一个连续的过程，而不是分离的)
9.  √ (Refactoring improves structure without changing external functions)
    √（重构改进结构而不改变外部功能）
10.  √ (SEI maturity model’s highest level is Optimizing)
    √（SEI 成熟度模型的最高级别是优化）

## Part 2: Fill-in-the-Blank
第二部分：填空题

1.  software evolution / 软件演化 
2.  Integration and configuration / 集成和配置 
3.  System testing / 系统测试 
4.  Incremental delivery / 增量式交付 
5.  Managed / 被管理级

## Part 3: Multiple Choice
第三部分：选择题

1.  B, C, D (Hardware is not part of software; professional software includes docs, config data, libraries)
    B、C、D（硬件不是软件的一部分；专业软件包括文档、配置数据和库）
2.  A, C (Incremental development facilitates feedback and improves visibility, so B/D are wrong)
    A、C（增量开发便于反馈并提高可见性，因此 B/D 是错误的）
3.  A, B, C (Market share is not related to process descriptions)
    A、B、C（市场份额与过程描述无关）

## Part 4: Single Choice
第四部分：单选题

1.  B (The type of application is the most significant factor, as per Chapter 1)
    B（根据第一章，应用类型是最重要的因素）

## Part 5: Subjective Question (Reference Answer)
第五部分：主观题（参考答案）

(1) **Significance of independent innovation**:
（1）独立创新的重大意义：

*   Avoid "chokepoint" risks: Independent software (e.g., EDA, industrial software) ensures the security of China’s industrial chain and supply chain, preventing external technical blockades.
    避免"卡脖子"风险：独立软件（例如 EDA、工业软件）确保中国产业链和供应链的安全，防止外部技术封锁。
*   Drive digital economy development: Independent software engineering technologies support the transformation of traditional industries (e.g., smart manufacturing, fintech) and promote high-quality economic growth.
    推动数字经济发展：独立软件工程技术支持传统产业（例如智能制造、金融科技）的转型，促进高质量发展。
*   Enhance international competitiveness: Leading software innovation helps China gain a voice in global digital governance and break the monopoly of foreign software in high-end fields.
    提升国际竞争力：领先的软件创新帮助中国在全球数字治理中获得话语权，打破外国软件在高端领域的垄断。

(2) **Abilities to develop**:
(2) 需要发展的能力：

*   Solid technical foundation: Master core SE technologies (e.g., system design, software reuse, reliable system development) to lay a foundation for independent R&D.
    扎实的理论基础：掌握核心软件工程技术（例如系统设计、软件复用、可靠系统开发），为独立研发奠定基础。
*   Innovative thinking: Cultivate the ability to solve complex technical problems (e.g., improving software efficiency, enhancing system security) and explore new software engineering methods.
    创新思维：培养解决复杂技术问题的能力（例如提高软件效率、增强系统安全）并探索新的软件工程技术。
*   Strategic vision: Understand the development trends of key technologies (e.g., AI-driven software development, open-source ecology) and focus on the needs of national key industries.
    战略眼光：了解关键技术发展趋势（例如人工智能驱动软件开发、开源生态）并聚焦国家重点产业需求。
*   Professional ethics: Adhere to the concept of "serving the country with technology" and ensure the reliability, security, and compliance of independently developed software.
    职业道德：坚持“科技报国”理念，确保自主研发软件的可靠性、安全性及合规性。