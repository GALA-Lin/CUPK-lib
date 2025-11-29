# Software Engineering (Bilingual) Review Reference: Chapter 3 (Agile Software Development)
软件工程（双语）复习参考：第三章（敏捷软件开发）

## Overview
概述

This review covers core knowledge of **Chapter 3 (Agile Software Development)** and aligns with the first quiz’s key exam points (multiple choice, single choice, true/false, fill-in-the-blank). Core content is presented in English with bilingual annotations for key terms to match the bilingual course requirements, and directly maps to quiz questions for targeted review.
本次复习涵盖第三章（敏捷软件开发）的核心知识，并与第一场测验的关键考试要点（选择题、单选题、判断题、填空题）相一致。核心内容以英文呈现，关键术语附有双语注释，以满足双语课程要求，并与测验题目直接对应，便于针对性复习。

## Core Knowledge Points (English + Bilingual Key Terms)
核心知识点（英文+双语关键术语）

### 1\. Agile Development Fundamentals
1\. 敏捷开发基础

#### 1.1 Core Characteristics (敏捷开发核心特性)

*   Program specification, design and implementation are **inter-leaved (相互交织)**.
    程序规范、设计和实现是相互交织的。
*   The system is developed in a series of **increments (增量)** (stakeholders participate in specifying/evaluating each increment).
    系统以一系列增量（增量）开发（利益相关者参与指定/评估每个增量）。
*   **Extensive tool support (广泛的工具支持)** (e.g., automated testing tools).
    广泛的工具支持（广泛的工具支持）（例如，自动化测试工具）。
*   **Minimal documentation (最小化文档)** (focus on working code rather than comprehensive docs).
    最小化文档（最小化文档）（侧重于可运行的代码而非全面文档）。

#### 1.2 Agile Principles (敏捷原则)
1.2 敏捷原则（敏捷原则）

| Principle原则 | Key Requirement主要要求 | Violation Example违规示例 |
| --- | --- | --- |
| Customer involvement客户参与 | Customers are closely involved throughout development.客户在整个开发过程中都紧密参与。 | Avoid customer involvement (violation)避免客户参与（违规） |
| Embrace change拥抱变化 | Expect and accommodate requirement changes.预期并适应需求变化。 | Ignore requirement changes (violation)忽略需求变更（违规） |
| Incremental delivery增量交付 | Develop software in increments (customer specifies requirements per increment).分阶段开发软件（客户为每个阶段指定需求）。 | One-time full delivery (violation)一次性完整交付（违规） |
| Maintain simplicity保持简洁 | Focus on simplicity in software/development process.专注于软件/开发过程中的简洁。 | Overcomplicate design/process (violation)过度复杂化设计/流程（违规） |
| People, not process以人为本，而非流程 | Leverage team skills (no prescriptive processes).利用团队技能（无规定流程）。 | Rigid process over team autonomy (violation)严格流程高于团队自主权（违反） |

#### 1.3 Applicability (敏捷方法适用性)

*   **Suitable for**: Small/medium-sized products, custom systems (clear customer commitment).
    适用于：中小型产品、定制系统（客户承诺明确）。
*   **Not ideal for**: Large-sized products (requires scaling; original agile methods are designed for small co-located teams).
    不适合：大型产品（需要扩展；原始敏捷方法是为小型同地团队设计的）。

### 2\. Extreme Programming (XP, 极限编程)
2\. 极限编程 (XP, 极限编程)

#### 2.1 Core Practices (XP核心实践)
2.1 核心实践 (XP 核心实践)

| Practice实践 | Definition & Key Notes定义与关键要点 |
| --- | --- |
| Refactoring (重构)重构 | Continuously improve code structure (even without immediate need) to simplify changes; NOT only for immediate needs.持续改进代码结构（即使没有立即需求）以简化变更；不仅是为了立即需求。 |
| Pair programming (结对编程)结对编程 | Developers work in dynamic pairs (not fixed pairs); acts as informal review (2+ people check code); encourages refactoring (NOT discourages).开发者以动态配对（非固定配对）方式工作；充当非正式审查（2 人以上检查代码）；鼓励重构（非抑制）。 |
| Incremental planning (增量式规划) | Requirements as "story cards" → broken into tasks; customer prioritizes stories for each release. |
| Test-first development (测试先行开发) | Write automated tests BEFORE code (test-driven development, TDD); tests clarify requirements and catch errors early. |
| On-site customer (现场客户)现场客户 | Customer is part of the team; develops acceptance tests (验收测试) for user stories.客户是团队的一员；为用户故事开发验收测试。 |

#### 2.2 Key Quiz Points for XP
2.2 XP 的关键测验要点

*   Refactoring: The main method to make software changes easier (XP核心手段).
    重构：使软件变更更容易的主要方法（XP 核心手段）。
*   Test-first development: "Writing tests before code" is TRUE (核心特征).
    单元测试优先开发："先写测试再写代码"是正确的（核心特征）。
*   Pair programming: Formal studies show **mixed results**; dynamic pair formation; encourages refactoring (NOT discourages).
    结对编程：正式研究显示结果不一；动态结对形成；鼓励重构（不抑制）。

### 3\. Scrum (敏捷项目管理框架)

#### 3.1 Core Terminology (Scrum核心术语)
3.1 核心术语（Scrum 核心术语）

| Term术语 | Definition (English)定义（英文） | 中文注释 |
| --- | --- | --- |
| Product backlog产品待办事项列表 | List of "to do" items (features/requirements/tasks) the Scrum team must tackle.Scrum 团队必须处理的“待办”项目（功能/需求/任务）列表。 | 产品待办事项 |
| Sprint | Fixed-time development iteration (2-4 weeks) to deliver a shippable increment.固定时间开发迭代（2-4 周），交付可发布的增量。 | 冲刺 |
| Product Owner产品负责人 | Prioritizes product backlog items (defines most important items to develop).优先排序产品积压项（定义最重要的开发项）。 | 产品拥有者 |
| Scrum Master | Facilitator (arranges daily meetings, tracks backlog, communicates with external stakeholders; NOT a project manager).促进者（安排每日会议、跟踪积压项、与外部利益相关者沟通；不是项目经理）。 | Scrum主管 |
| Daily Scrum每日站会 | Short daily meeting to review progress/prioritize work.简短的每日会议，用于回顾进度/优先排序工作。 | 每日站立会议 |

#### 3.2 Roles & Responsibilities (角色与职责)
3.2 角色与职责

*   **Project manager**: Responsible for delivering software on time/within budget (agile project management core responsibility).
    项目经理：负责按时/在预算内交付软件（敏捷项目管理的核心职责）。
*   **Scrum Master**: Manages daily Scrum, tracks backlog, external communication (NOT product backlog prioritization).
    Scrum Master：管理每日 Scrum，跟踪待办事项列表，外部沟通（非产品待办事项优先级排序）。
*   **Product Owner**: Prioritizes product backlog (key responsibility for sprint planning).
    产品负责人：确定产品待办事项优先级（冲刺计划的关键职责）。

### 4\. Agile Maintenance & Scaling Agile Methods
4\. 敏捷维护与敏捷方法扩展

#### 4.1 Agile Maintenance (敏捷维护) 

*   **Three key problems**:  
    1.  Lack of product documentation (产品文档缺失). 
    2.  Customer involvement (客户参与度下降 during maintenance). 
    3.  Development team continuity (开发团队延续性差).
        开发团队延续性差。

#### 4.2 Scaling Agile for Large Systems (敏捷方法伸缩)
4.2 敏捷方法伸缩

*   **Systems of systems (系统之系统)**: Large systems integrating/interacting with multiple existing systems (key term for large-scale agile).
    系统之系统：大型系统整合/交互多个现有系统（大型敏捷的关键术语）。
*   **Agile for large systems**: Original agile methods (for small teams) need scaling (e.g., multi-team Scrum, up-front design, cross-team communication).
    大型系统敏捷：原始敏捷方法（适用于小团队）需要扩展（例如，多团队 Scrum、前期设计、跨团队沟通）。
*   **Team skills**: Agile methods work best with **high/consistent skill levels** (NOT wide range of skills/abilities → quiz Q20 is FALSE).
    团队技能：敏捷方法最适合高/稳定技能水平（不是广泛技能/能力→测验第 20 题是错误的）。

## Corresponding Quiz Exam Points
相应的测验考试要点

| Question Type题型 | Quiz Question Number测验题号 | Core Topic & Key Answer核心主题与关键答案 |
| --- | --- | --- |
| Multiple Choice选择题 | 1 | Agile development characteristics → A (inter-leaved), B (increments), C (tool support), D (minimal docs) (all correct).敏捷开发特征 → A（交错式），B（增量式），C（工具支持），D（最少文档）（全部正确）。 |
| Single Choice单选题 | 2 | Violation of agile principles → A (Avoid customer involvement).违反敏捷原则 → A（避免客户参与）。 |
| Single Choice单选题 | 3 | False about agile applicability → C (large-sized products).关于敏捷适用性的错误说法 → C（大型产品）。 |
| Multiple Choice多选题 | 4 | XP practices → A (Refactoring), B (Pair programming), C (Incremental planning), D (Test-first development) (all correct).XP 实践 → A（重构）、B（结对编程）、C（增量规划）、D（测试驱动开发）（全部正确）。 |
| True/False | 6 | XP refactoring only for immediate need → FALSE (refactor even without immediate need).XP 重构只为立即需求 → FALSE（即使没有立即需求也要重构）。 |
| Single Choice单选 | 7 | XP method for easier changes → C (Refactoring).XP 方法以实现更易变更 → C（重构）。 |
| True/False | 8 | Test-driven development: write tests before code → TRUE.测试驱动开发：先写测试再写代码 → TRUE。 |
| Fill-in-the-Blank填空题 | 9 | Customer’s role in testing → \[acceptance/验收\] tests.客户在测试中的角色：\[验收\] 测试。 |
| Single Choice单选 | 10 | False about pair-programming → D (Discourages refactoring).关于结对编程的误解 → D（抑制重构）。 |
| Single Choice单选题 | 11 | Agile project delivery/budget responsibility → B (Project manager).敏捷项目交付/预算责任 → B（项目经理）。 |
| Single Choice单选题 | 12 | Scrum "to do" list → B (backlog).Scrum "待办"列表 → B（积压事项）。 |
| Single Choice单选 | 14 | Prioritize product backlog → A (Product owner).优先排序产品积压事项 → A（产品负责人）。 |
| Single Choice单选 | 15 | Scrum daily meetings/tracking → B (Scrum master).每日 Scrum 会议/跟踪 → B（Scrum 主管）。 |
| Multiple Choice单选题 | 17 | Agile maintenance key problems → A (Lack of docs), C (Customer involvement), D (Team continuity).敏捷维护的关键问题 → A（缺乏文档）、C（客户参与）、D（团队连续性）。 |
| Single Choice单选题 | 19 | Large systems with multiple existing systems → B (systems of systems).大型系统包含多个现有系统 → B（系统之系统）。 |
| True/False对/错 | 20 | Agile works best with wide skill range → FALSE (works best with high/consistent skills).敏捷开发在广泛技能范围内效果最佳 → 错（在高度/一致技能范围内效果最佳）。 |

## Key Review Suggestions
关键审查建议

1.  **Agile Core Characteristics/Principles**: Memorize the 4 core characteristics and 5 agile principles (focus on "customer involvement" and "embrace change" – frequent violation questions).
    敏捷的核心特征/原则：记住 4 个核心特征和 5 个敏捷原则（重点在于“客户参与”和“拥抱变化”——频繁违反问题的点）。
2.  **XP Practices**: Master refactoring, test-first development, and pair programming (key single-choice/false questions; e.g., refactoring is NOT only for immediate needs).
    XP 实践：掌握重构、测试驱动开发和结对编程（关键单选题/判断题；例如，重构不仅是为了立即需求）。
3.  **Scrum Terminology & Roles**: Distinguish Product Owner (prioritize backlog), Scrum Master (facilitate process), and Project Manager (delivery/budget) – critical for single-choice questions.
    Scrum 术语与角色：区分产品负责人（优先处理产品待办列表）、Scrum 主管（促进流程）和项目经理（交付/预算）——这对单选题至关重要。
4.  **Agile Applicability & Scaling**: Remember agile is for small/medium products; large systems need scaling (key term: systems of systems).
    敏捷适用性与扩展：记住敏捷适用于中小型产品；大型系统需要扩展（关键术语：系统之系统）。
5.  **Agile Maintenance**: Focus on the 3 key problems (lack of docs, customer involvement, team continuity) – multiple-choice exam point.
    敏捷维护：关注三个关键问题（缺乏文档、客户参与、团队连续性）——多选题考点。