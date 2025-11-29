# Software Engineering (Bilingual) Review Reference: Chapter 3 (Agile Software Development)
## Overview
This review covers core knowledge of **Chapter 3 (Agile Software Development)** and aligns with the first quiz’s key exam points (multiple choice, single choice, true/false, fill-in-the-blank). Core content is presented in English with bilingual annotations for key terms to match the bilingual course requirements, and directly maps to quiz questions for targeted review.

## Core Knowledge Points (English + Bilingual Key Terms)
### 1. Agile Development Fundamentals
#### 1.1 Core Characteristics (敏捷开发核心特性)
- Program specification, design and implementation are **inter-leaved (相互交织)**.
- The system is developed in a series of **increments (增量)** (stakeholders participate in specifying/evaluating each increment).
- **Extensive tool support (广泛的工具支持)** (e.g., automated testing tools).
- **Minimal documentation (最小化文档)** (focus on working code rather than comprehensive docs).

#### 1.2 Agile Principles (敏捷原则)
| Principle            | Key Requirement                                              | Violation Example                            |
| -------------------- | ------------------------------------------------------------ | -------------------------------------------- |
| Customer involvement | Customers are closely involved throughout development.       | Avoid customer involvement (violation)       |
| Embrace change       | Expect and accommodate requirement changes.                  | Ignore requirement changes (violation)       |
| Incremental delivery | Develop software in increments (customer specifies requirements per increment). | One-time full delivery (violation)           |
| Maintain simplicity  | Focus on simplicity in software/development process.         | Overcomplicate design/process (violation)    |
| People, not process  | Leverage team skills (no prescriptive processes).            | Rigid process over team autonomy (violation) |

#### 1.3 Applicability (敏捷方法适用性)
- **Suitable for**: Small/medium-sized products, custom systems (clear customer commitment).
- **Not ideal for**: Large-sized products (requires scaling; original agile methods are designed for small co-located teams).

### 2. Extreme Programming (XP, 极限编程)
#### 2.1 Core Practices (XP核心实践)
| Practice                              | Definition & Key Notes                                       |
| ------------------------------------- | ------------------------------------------------------------ |
| Refactoring (重构)                    | Continuously improve code structure (even without immediate need) to simplify changes; NOT only for immediate needs. |
| Pair programming (结对编程)           | Developers work in **dynamic pairs** (not fixed pairs); acts as informal review (2+ people check code); encourages refactoring (NOT discourages). |
| Incremental planning (增量式规划)     | Requirements as "story cards" → broken into tasks; customer prioritizes stories for each release. |
| Test-first development (测试先行开发) | Write **automated tests BEFORE code** (test-driven development, TDD); tests clarify requirements and catch errors early. |
| On-site customer (现场客户)           | Customer is part of the team; develops **acceptance tests (验收测试)** for user stories. |

#### 2.2 Key Quiz Points for XP
- Refactoring: The main method to make software changes easier (XP核心手段).
- Test-first development: "Writing tests before code" is TRUE (核心特征).
- Pair programming: Formal studies show **mixed results**; dynamic pair formation; encourages refactoring (NOT discourages).

### 3. Scrum (敏捷项目管理框架)
#### 3.1 Core Terminology (Scrum核心术语)
| Term            | Definition (English)                                         | 中文注释     |
| --------------- | ------------------------------------------------------------ | ------------ |
| Product backlog | List of "to do" items (features/requirements/tasks) the Scrum team must tackle. | 产品待办事项 |
| Sprint          | Fixed-time development iteration (2-4 weeks) to deliver a shippable increment. | 冲刺         |
| Product Owner   | Prioritizes product backlog items (defines most important items to develop). | 产品拥有者   |
| Scrum Master    | Facilitator (arranges daily meetings, tracks backlog, communicates with external stakeholders; NOT a project manager). | Scrum主管    |
| Daily Scrum     | Short daily meeting to review progress/prioritize work.      | 每日站立会议 |

#### 3.2 Roles & Responsibilities (角色与职责)
- **Project manager**: Responsible for delivering software on time/within budget (agile project management core responsibility).
- **Scrum Master**: Manages daily Scrum, tracks backlog, external communication (NOT product backlog prioritization).
- **Product Owner**: Prioritizes product backlog (key responsibility for sprint planning).

### 4. Agile Maintenance & Scaling Agile Methods
#### 4.1 Agile Maintenance (敏捷维护)
- **Three key problems**:
  1. Lack of product documentation (产品文档缺失).
  2. Customer involvement (客户参与度下降 during maintenance).
  3. Development team continuity (开发团队延续性差).

#### 4.2 Scaling Agile for Large Systems (敏捷方法伸缩)
- **Systems of systems (系统之系统)**: Large systems integrating/interacting with multiple existing systems (key term for large-scale agile).
- **Agile for large systems**: Original agile methods (for small teams) need scaling (e.g., multi-team Scrum, up-front design, cross-team communication).
- **Team skills**: Agile methods work best with **high/consistent skill levels** (NOT wide range of skills/abilities → quiz Q20 is FALSE).

## Corresponding Quiz Exam Points
| Question Type     | Quiz Question Number | Core Topic & Key Answer                                      |
| ----------------- | -------------------- | ------------------------------------------------------------ |
| Multiple Choice   | 1                    | Agile development characteristics → A (inter-leaved), B (increments), C (tool support), D (minimal docs) (all correct). |
| Single Choice     | 2                    | Violation of agile principles → A (Avoid customer involvement). |
| Single Choice     | 3                    | False about agile applicability → C (large-sized products).  |
| Multiple Choice   | 4                    | XP practices → A (Refactoring), B (Pair programming), C (Incremental planning), D (Test-first development) (all correct). |
| True/False        | 6                    | XP refactoring only for immediate need → FALSE (refactor even without immediate need). |
| Single Choice     | 7                    | XP method for easier changes → C (Refactoring).              |
| True/False        | 8                    | Test-driven development: write tests before code → TRUE.     |
| Fill-in-the-Blank | 9                    | Customer’s role in testing → [acceptance/验收] tests.        |
| Single Choice     | 10                   | False about pair-programming → D (Discourages refactoring).  |
| Single Choice     | 11                   | Agile project delivery/budget responsibility → B (Project manager). |
| Single Choice     | 12                   | Scrum "to do" list → B (backlog).                            |
| Single Choice     | 14                   | Prioritize product backlog → A (Product owner).              |
| Single Choice     | 15                   | Scrum daily meetings/tracking → B (Scrum master).            |
| Multiple Choice   | 17                   | Agile maintenance key problems → A (Lack of docs), C (Customer involvement), D (Team continuity). |
| Single Choice     | 19                   | Large systems with multiple existing systems → B (systems of systems). |
| True/False        | 20                   | Agile works best with wide skill range → FALSE (works best with high/consistent skills). |

## Key Review Suggestions
1. **Agile Core Characteristics/Principles**: Memorize the 4 core characteristics and 5 agile principles (focus on "customer involvement" and "embrace change" – frequent violation questions).
2. **XP Practices**: Master refactoring, test-first development, and pair programming (key single-choice/false questions; e.g., refactoring is NOT only for immediate needs).
3. **Scrum Terminology & Roles**: Distinguish Product Owner (prioritize backlog), Scrum Master (facilitate process), and Project Manager (delivery/budget) – critical for single-choice questions.
4. **Agile Applicability & Scaling**: Remember agile is for small/medium products; large systems need scaling (key term: systems of systems).
5. **Agile Maintenance**: Focus on the 3 key problems (lack of docs, customer involvement, team continuity) – multiple-choice exam point.