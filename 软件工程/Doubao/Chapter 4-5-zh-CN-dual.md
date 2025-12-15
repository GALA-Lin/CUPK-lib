# Software Engineering (Bilingual) Review Reference: Chapters 4-5
软件工程（双语）综述参考：第4-5章

## Overview
概述

This review focuses on core knowledge of **Chapter 4 (Requirements Engineering)** and **Chapter 5 (System Modeling)**, aligned with the second assignment’s key exam points (true/false, fill-in-the-blank, multiple choice, single choice). Core content is presented in English with bilingual key term annotations for clarity, and directly maps to assignment questions for targeted review.
本综述重点关注**第四章（需求工程）** 和**第五章（系统建模）** 的核心知识，并与第二项作业的关键考试点（对错题、填空题、选择题、单选题）相呼应。核心内容以英语呈现，并配有双语关键词注释以提升清晰度，并直接对应作业题目以便有针对性复习。

## Chapter 4: Requirements Engineering
第四章：需求工程

### Core Knowledge Points (English + Bilingual Key Terms)
核心知识点（英语 + 双语关键词）

#### 1\. Basic Concepts
1\. 基本概念

*   **Requirements Classification**:
    **需求分类** ：
    *   User requirements (用户需求): High-level, abstract statements of services/constraints (natural language + diagrams).
        用户需求（用户需求）：高层次、抽象的服务/约束陈述（自然语言+图表）。
    *   System requirements (系统需求): Detailed descriptions of functions, services, and constraints (contractual basis for development).
        系统需求（系统需求）：详细描述功能、服务和约束（开发的合同基础）。
*   **Stakeholders (干系人)**: Any person affected by the system (e.g., users, managers, regulators).
    **利益相关者（干系人）：** 任何受系统影响的人（如用户、管理者、监管者）。
*   **Functional vs. Non-Functional Requirements**:
    **功能性需求与非功能性需求** ：
    *   Functional requirements (功能需求): Services the system provides, reactions to inputs (e.g., "search appointments").
        功能需求（功能需求）：系统提供的服务，对输入的反应（例如，“搜索约会”）。
    *   Non-functional requirements (非功能需求): Constraints on the system (e.g., reliability, speed); often more critical than individual functional requirements.
        非功能需求（非功能需求）：系统约束（如可靠性、速度）;通常比单个功能需求更为关键。

#### 2\. Requirements Engineering Process
2\. 需求工程流程

*   **Key Activities**: Elicitation (抽取) → Specification (规格说明) → Validation (确认) → Change Management (变更管理) (iterative and interleaved).
    **关键活动** ：抽取（Elicitation）→规格说明（Elicitation 规格说明→确认（Validation）→变更管理（变更管理）（迭代和交错）。
*   **Elicitation Techniques**:
    **引诱技巧** ：
    *   Interviewing (访谈): Closed (predefined questions) + Open (no agenda).
        访谈（访谈）：封闭式（预设问题）+ 开放式（无议程）。
    *   Observation/ethnography (人种志): Immersive observation to discover implicit requirements.
        观察/民族志（人种志）：沉浸式观察，旨在发现隐性需求。
    *   User stories/scenarios (用户故事/场景): Narrative descriptions of system use.
        用户故事/场景（用户故事/场景）：系统使用的叙述性描述。
*   **Specification Methods**:
    **规范方法** ：
    *   Natural language (structured for consistency).
        自然语言（结构化以保证一致性）。
    *   Form-based/tabular specifications (for alternative scenarios).
        基于表单/表格的规范（适用于替代场景）。
    *   UML diagrams (use cases, sequence diagrams).
        UML 图（用例，时序图）。
*   **Validation (确认)**: Check requirements for validity, consistency, completeness, realism, verifiability (errors here cause the most rework).
    **验证（确认）：** 检查其有效性、一致性、完整性、真实性、可验证性（此处错误最容易导致重做）。
*   **Change Management (变更管理)**: 3 stages → Problem analysis & change specification → Change analysis & costing → Change implementation (变更实现).
    **变更管理（变更管理）：** 三阶段→问题分析与变更规范 →变更分析与成本核算 →变更实现（变更实现）。

#### 3\. Critical Metrics & Guidelines
3\. 关键指标与指导方针

*   **Non-Functional Requirement Metrics**: Speed (response time), ease of use (training time), reliability (mean time to failure), robustness (failure recovery time).
    **非功能需求指标** ：速度（响应时间）、易用性（训练时间）、可靠性（平均故障时间）、鲁棒性（故障恢复时间）。
*   **Writing Guidelines**: Use "shall" (mandatory) vs. "should" (desirable); avoid jargon; associate rationale with requirements.
    **写作指南：使用** “shall”（强制）与“应当”（wishirable）;避免使用行话;将理由与要求联系起来。

### Corresponding Assignment Exam Points
对应作业考试积分

| Question Type问题类型 | Typical Topics & Examples典型主题与示例 |
| --- | --- |
| True/False真/假 | \- "Non-functional requirements are less critical than functional ones" (False)- “非功能性需求不如功能性需求重要”（错误）- "A single non-functional requirement may generate related functional requirements" (True)- “单个非功能性需求可能产生相关的功能需求”（真）- "Agile development skips formal change management" (False)- “敏捷开发跳过正式的变更管理”（错误）- "Form-based specs suit alternative scenarios" (False)- “基于形态的规格适合替代场景”（错误） |
| Fill-in-the-Blank填空 | \- Detailed requirements: \[system/系统\]- 详细需求：\[系统/系统\]- Elicitation technique: \[ethnography/人种志\]- 引发技巧：\[民族志/人种志\]- Change management final stage: \[change implementation/变更实现\]- 变更管理最终阶段：\[变更实现/变更实现\] |
| Multiple Choice选择题 | \- Non-functional requirement metrics (A: Speed; B: Ease of use; C: Reliability; D: Robustness)- 非功能性需求指标（A：速度;B：易用性;C：可靠性;D：稳健性） |
| Single Choice单选题 | \- Definition of stakeholders (B: Any person affected by the system)- 利益相关者的定义（B：受系统影响的任何人员）- Functional requirement example (C: Services the system should provide)- 功能需求示例（C：系统应提供的服务）- Unverifiable non-functional requirement (D: "Easy to use by medical staff")- 无法验证的非功能性需求（D：“医务人员易于使用”）- Actor in use case diagram (A: Generate report – it’s a use case, not an actor)- 用例图中的演员（A：生成报告——这是一个用例，而非演员）- Document causing most rework (D: Requirements document)- 导致大部分重做的文档（D：需求文档） |

## Chapter 5: System Modeling
第五章：系统建模

### Core Knowledge Points (English + Bilingual Key Terms)
核心知识点（英语 + 双语关键词）

#### 1\. Basic Concepts
1\. 基本概念

*   **System Modeling (系统建模)**: Developing abstract models to show system perspectives (external, interaction, structural, behavioral).
    **系统建模（系统建模）：** 开发抽象模型以展示系统视角（外部、交互、结构、行为）。
*   **UML (Unified Modeling Language)**: 5 core diagrams for essentials: Activity diagrams (活动图), Use case diagrams (用例图), Sequence diagrams (顺序图), Class diagrams (类图), State diagrams (状态图).
    **UML（统一建模语言）：**5 个核心图：活动图（活动图）、用例图、序列图（顺序图）、类图（类图）、状态图（状态图）。

#### 2\. Key Model Types
2\. 关键模型类型

*   **Context Models (上下文模型)**: Define system boundaries (边界) and dependencies with external systems (e.g., Mentcare system’s connections to other hospital systems).
    **上下文模型（上下文模型）：** 定义系统边界（边界）及与外部系统的依赖关系（例如，Mentcare 系统与其他医院系统的连接）。
*   **Interaction Models (交互模型)**:
    **交互模型（交互模型）：**
    *   Use case diagrams: Show actors (human/external systems) and discrete interactions (ellipses).
        用例图：显示参与者（人类/外部系统）和离散交互（椭圆）。
    *   Sequence diagrams: Show interaction order (vertical lifelines, annotated arrows, "alt" for alternatives).
        时序图：显示交互顺序（垂直生命线、注释箭头、替代选项）。
*   **Structural Models (结构模型)**:
    **结构模型（结构模型）：**
    *   Class diagrams: Show classes, associations (1:1, 1:\*), attributes, operations.
        类图：显示类、关联（1：1,1：\*）、属性、运算。
    *   Generalization (泛化): Inheritance (superclass → subclass, e.g., Doctor → Hospital Doctor).
        泛化（泛化）：继承（超类→子类，例如医生→医院医生）。
    *   Aggregation (聚集): "Whole-part" relationship (diamond notation, e.g., Patient Record → Patient + Consultations).
        聚合（聚集）：“整体”关系（菱形符号，例如患者记录→患者+咨询）。
*   **Behavioral Models (行为模型)**:
    **行为模型（行为模型）：**
    *   Activity diagrams: Data-driven (process steps + data flow; solid bars for parallel activities).
        活动图：数据驱动（流程步骤 + 数据流;实心条表示平行活动）。
    *   State diagrams: Event-driven (system states + transitions, e.g., microwave oven’s "Waiting" → "Full power").
        状态图：事件驱动（系统状态 + 转换，例如微波炉的“等待”→“全功率”）。
*   **Model-Driven Architecture (MDA)**: 3 models → CIM (Computation Independent Model) → PIM (Platform Independent Model/平台无关模型) → PSM (Platform Specific Model); transformations may need human intervention (CIM→PIM).
    **模型驱动架构（MDA）：** 三种模型→CIM（计算无关模型）→PIM（平台无关模型）→PSM（平台特定模型）;转化可能需要人工干预（CIM→PIM）。

### Corresponding Assignment Exam Points
对应作业考试积分

| Question Type问题类型 | Typical Topics & Examples典型主题与示例 |
| --- | --- |
| True/False真/假 | \- "MDE includes model-based testing, MDA does not" (False)- “MDE 包含基于模型的测试，MDA 不包括”（错误）- "Agile methods and MDA have an uneasy relationship" (True)- “敏捷方法与 MDA 之间存在微妙关系”（True） |
| Fill-in-the-Blank填空 | \- System model dimension: \[perspective/视角\]- 系统模型维度：\[透视/视角\]- System scope definition: \[boundaries/边界\]- 系统范围定义：\[边界/边界\]- "Whole-part" association: \[aggregation/聚集\]- “整体”关联：\[聚合/聚集\]- Behavioral stimulus type: \[data/数据\]- 行为刺激类型：\[数据/数据\]- MDA middle model: \[PIM/平台无关模型\]- MDA 中间模型：\[PIM/平台无关模型\]- Platform adaptation tool: \[translator/转换器\]- 平台适配工具：\[translator/转换器\] |
| Multiple Choice选择题 | \- Interaction models (C: Use case diagrams; D: Sequence diagrams)- 交互模型（C：用例图;D：时序图） |
| Single Choice单选题 | \- Non-UML diagram (A: Block diagrams)- 非 UML 图（A：方块图）- False activity diagram statement (C: "One of three parallel activities completes → diagram ends")- 虚假活动图语句（C：“三个并行活动之一完成→图结束”）- False sequence diagram statement (D: "Error occurs before Patient info")- 错误的序列图陈述（D：“错误发生在患者信息之前”）- 1-to-many class relationship (B: Patient → Consultation)- 1 对多类别关系（B：患者与会诊→）- False generalization statement (B: "Doctor has Staff # attribute" – subclass Hospital Doctor has it)- 错误概括陈述（B：“医生有员工#属性”——子职业医院医生拥有）- Event-driven modeling diagram (B: State diagram)- 事件驱动建模图（B：状态图）- MDA transformation needing human intervention (A: CIM→PIM)- 需要人类干预的 MDA 转化（A：CIM→PIM） |

## 1\. English-Chinese Bilingual Glossary (Chapters 4-5)
1\. 英中双语词汇表（第4-5章）

| Category类别 | English Term英语术语 | Chinese Term中文术语 | Assignment Relevance分配相关性 |
| --- | --- | --- | --- |
| Requirements Engineering需求工程 | User requirements用户需求 | 用户需求 | 填空题考点（与system requirements对应） |
|  | System requirements系统需求 | 系统需求 | 填空题核心答案 |
|  | Stakeholders利益相关者 | 干系人 | 单选题定义考点 |
|  | Ethnography民族志 | 人种志 | 需求抽取技术填空题 |
|  | Change implementation变更的实施 | 变更实现 | 变更管理流程填空题 |
|  | Non-functional requirements (NFR)非功能需求（NFR） | 非功能需求 | 判断题/多选题考点 |
| System Modeling系统建模 | System boundaries系统边界 | 系统边界 | 上下文模型填空题 |
|  | Aggregation集合体 | 聚集 | 结构模型关联类型填空题 |
|  | Generalization普遍化 | 泛化 | 类图继承关系单选题 |
|  | Sequence diagram时序图 | 顺序图 | 交互模型判断题/单选题 |
|  | State diagram状态图 | 状态图 | 行为模型单选题 |
| MDA | PIM (Platform Independent Model)PIM（平台独立模型） | 平台无关模型 | MDA三层模型填空题 |
|  | Translator在线翻译 | 转换器 | MDA平台适配填空题 |

## 2\. Mock Test (Chapters 4-5)
2\. 模拟测试（第4-5章）

### Test Information
考试信息

*   Total Questions: 15 (5 True/False, 5 Fill-in-the-Blank, 3 Multiple Choice, 2 Single Choice)
    总题数：15道（5道真/错，5道填空题，3道选择题，2道单选题）
*   Total Score: 15 Points
    总得分：15分

#### Part 1: True/False (1 point each)
第一部分：是非题（每题1分）

1.  Functional requirements describe what the system should do, while non-functional requirements define constraints. ( )
    功能需求描述系统应执行的任务，而非功能需求定义约束。( )
2.  Ethnography is effective for discovering explicit user requirements. ( )
    民族志对于发现明确的用户需求非常有效。( )
3.  A requirements document error leads to more rework than a coding error. ( )
    需求文档错误导致的重做比编码错误更多。( )
4.  Aggregation in UML represents an inheritance relationship between classes. ( )
    UML 中的聚合表示类之间的继承关系。( )
5.  PIM-to-PSM transformation in MDA requires no human intervention. ( )
    MDA 中的 PIM 转 PSM 转变无需人工干预。( )

#### Part 2: Fill-in-the-Blank (1 point each)
第二部分：填空题（每题1分）

1.  Stakeholders are any person who is \_\_\_\_\_\_\_\_\_\_\_\_\_\_ (affected by the system/受系统影响) in some way.
    利益相关者是指任何以某种方式受到系统\_\_\_\_\_\_\_\_\_\_\_\_\_\_影响（受系统影响）的人。
2.  The three stages of requirements change management include **Problem analysis & change specification → Change analysis & costing → Change implementation.**
    需求变更管理的三个阶段包括问题分析、变更分析和\_\_\_\_\_\_\_\_\_\_\_\_\_\_（变更实现）。
3.  In UML, \_\_\_\_\_\_\_\_\_\_\_\_\_\_ (state diagram/状态图) is used for event-driven behavioral modeling.
    在 UML 中，\_\_\_\_\_\_\_\_\_\_\_\_\_\_（状态图/状态图）用于事件驱动的行为建模。
4.  The "whole-part" association in class diagrams is called \_\_\_\_\_\_\_\_\_\_\_\_\_\_ (aggregation/聚集).
    类图中的“整部分”关联称为\_\_\_\_\_\_\_\_\_\_\_\_\_\_（聚合/聚集）。
5.  MDA defines three models: CIM, \_\_\_\_\_\_\_\_\_\_\_\_\_\_ (PIM/平台无关模型), and PSM.
    MDA 定义了三种模型：CIM、\_\_\_\_\_\_\_\_\_\_\_\_\_\_（PIM/平台无关模型）和 PSM。

#### Part 3: Multiple Choice (2 points each, partial score for incomplete selection)
第三部分：选择题（每部分2分，未完成选题部分得分）

1.  Which of the following are non-functional requirement metrics? ( )
    以下哪些是非功能性需求指标？( )
    A. Response time
    答：响应时间
    B. Number of system functions
    B. 系统功能的数量
    C. Mean time to failure
    C. 平均失效时间
    D. Training time for users
    D. 用户培训时间
    
2.  Which diagrams belong to UML core diagrams? ( )
    哪些图属于 UML 核心图？( )
    A. Activity diagrams
    答：活动图
    B. Block diagrams
    B. 框图
    C. Use case diagrams
    C. 用例图
    D. Sequence diagrams
    D. 时序图
    
3.  Which are requirements elicitation techniques? ( )
    哪些是需求获取技巧？( )
    A. Interviewing
    答：面试
    B. Ethnography
    B. 民族志
    C. Use case modeling
    C. 用例建模
    D. Prototyping
    D. 原型制作
    

#### Part 4: Single Choice (1 point each)
第四部分：单选题（每题1分）

1.  Which statement about generalization is true? ( )
    关于泛化的哪个说法是真的？( )
    A. Subclasses inherit attributes/operations from superclasses
    答：子类继承来自超类的属性/作
    B. It represents a "whole-part" relationship
    B.它代表一种“整体”关系
    C. It is denoted by a diamond in UML
    C.在 UML 中用菱形表示
    D. Superclasses add specific attributes to subclasses
    D. 超职业为子职业添加特定属性
    
2.  Why is requirements validation critical? ( )
    为什么需求验证至关重要？( )
    A. It reduces coding time
    一个。它减少了编码时间
    B. Errors here cause the most extensive rework
    B. 这里的错误会导致最大规模的重做
    C. It simplifies change management
    C.它简化了变更管理
    D. It ensures compliance with coding standards
    D.它确保符合编码标准
    

### Mock Test Answer Key
模拟考试答案

#### Part 1: True/False
第一部分：真/假

1.  √
2.  × (Ethnography discovers implicit requirements)
    ×（民族志发现隐性需求）
3.  √
4.  × (Aggregation = whole-part; generalization = inheritance)
    ×（聚合=整部分;推广=继承）
5.  × (CIM→PIM needs human intervention)
    ×（CIM→PIM 需要人工干预）

#### Part 2: Fill-in-the-Blank
第二部分：填空

1.  affected by the system
    受系统影响
2.  change implementation
    变更实施
3.  state diagram
    状态图
4.  aggregation
    集合体
5.  PIM

#### Part 3: Multiple Choice
第三部分：选择题

1.  A, C, D (B is a functional requirement metric)
    A、C、D（B 是功能需求指标）
2.  A, C, D (B is not a UML diagram)
    A、C、D（B 不是 UML 图）
3.  A, B, D (C is a specification method)
    A、B、D（C 是一种规范方法）

#### Part 4: Single Choice
第四部分：单选题

1.  A
2.  B

## Review Suggestions
评测建议

1.  Focus on **UML diagram distinctions**: Master the purpose of each core diagram (e.g., activity = process flow; sequence = interaction order; state = event response).
    专注于 **UML 图的区分** ：掌握每个核心图的目的（例如，活动=流程;序列=交互顺序;状态=事件响应）。
2.  Memorize **key processes**: Requirements engineering workflow, change management stages, MDA model transformations.
    记住**关键流程** ：需求工程工作流程、变更管理阶段、MDA 模型转换。
3.  Differentiate **critical concepts**: Functional vs. non-functional requirements, generalization vs. aggregation, user vs. system requirements.
    区分**关键概念** ：功能性需求与非功能性需求，泛化与聚合，用户需求与系统需求。
4.  Practice with assignment questions: Link each question to the corresponding knowledge point (e.g., "unverifiable NFR" → guideline for writing NFRs).
    练习作业题：将每题对应的知识点（例如，写 NFR 的指导，“不可验证 NFR”→）。

Would you like me to create a **UML diagram cheat sheet** (English + Chinese annotations) summarizing core symbols and use cases for quick review?

## UML核心图对比表格（重点记忆版）

| 维度             | 1. 类图 (Class Diagram)                                      | 2. 用例图 (Use Case Diagram)                     | 3. 顺序图 (Sequence Diagram)                                 | 4. 活动图 (Activity Diagram)                            | 5. 状态图 (State Diagram)                                 |
| ---------------- | ------------------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------- | --------------------------------------------------------- |
| **所属类别**     | 结构型（静态）                                               | 行为型（交互）                                   | 行为型（交互）                                               | 行为型（流程）数据驱动                                  | 行为型（事件驱动）                                        |
| **核心用途**     | 展示类、属性、操作及关系                                     | 展示系统与外部参与者的交互                       | 展示按时间顺序的实体交互                                     | 展示数据驱动的流程/步骤                                 | 展示对象因事件的状态变化                                  |
| **关键元素**     | 3段矩形（类名→属性→操作）、关联线、泛化（空心箭头）、聚集（菱形） | 参与者（ stick figure ）、用例（椭圆）、关联线   | 生命线（虚线）、消息（箭头）、alt分支（条件）                | 活动（圆角矩形）、并行网关（实心 bar ）、决策点（菱形） | 状态（圆角矩形）、转移（带事件箭头）、初始/终态（实心圆） |
| **课程案例关联** | Mentcare系统中`Patient`与`Consultation`的1:*关联             | Mentcare系统中“医疗接待员”执行“挂号”“传数据”用例 | Mentcare系统“查看患者信息”：接待员→数据库→授权系统的交互顺序 | 精神科“非自愿留置”流程：确认决策后并行通知患者+记录     | 微波炉“待机→全功率→加热完成”的状态切换                    |
| **记忆口诀**     | 类属操，关系找                                               | 人椭圆，交互连                                   | 时间线，消息传                                               | 步骤流，并行分                                          | 状态变，事件牵                                            |