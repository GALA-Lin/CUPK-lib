# Software Engineering (Bilingual) Review Reference: Chapters 4-5
## Overview
This review focuses on core knowledge of **Chapter 4 (Requirements Engineering)** and **Chapter 5 (System Modeling)**, aligned with the second assignment’s key exam points (true/false, fill-in-the-blank, multiple choice, single choice). Core content is presented in English with bilingual key term annotations for clarity, and directly maps to assignment questions for targeted review.


## Chapter 4: Requirements Engineering
### Core Knowledge Points (English + Bilingual Key Terms)
#### 1. Basic Concepts
- **Requirements Classification**:
  - User requirements (用户需求): High-level, abstract statements of services/constraints (natural language + diagrams).
  - System requirements (系统需求): Detailed descriptions of functions, services, and constraints (contractual basis for development).
- **Stakeholders (干系人)**: Any person affected by the system (e.g., users, managers, regulators).
- **Functional vs. Non-Functional Requirements**:
  - Functional requirements (功能需求): Services the system provides, reactions to inputs (e.g., "search appointments").
  - Non-functional requirements (非功能需求): Constraints on the system (e.g., reliability, speed); often more critical than individual functional requirements.

#### 2. Requirements Engineering Process
- **Key Activities**: Elicitation (抽取) → Specification (规格说明) → Validation (确认) → Change Management (变更管理) (iterative and interleaved).
- **Elicitation Techniques**:
  - Interviewing (访谈): Closed (predefined questions) + Open (no agenda).
  - Observation/ethnography (人种志): Immersive observation to discover implicit requirements.
  - User stories/scenarios (用户故事/场景): Narrative descriptions of system use.
- **Specification Methods**:
  - Natural language (structured for consistency).
  - Form-based/tabular specifications (for alternative scenarios).
  - UML diagrams (use cases, sequence diagrams).
- **Validation (确认)**: Check requirements for validity, consistency, completeness, realism, verifiability (errors here cause the most rework).
- **Change Management (变更管理)**: 3 stages → Problem analysis & change specification → Change analysis & costing → Change implementation (变更实现).

#### 3. Critical Metrics & Guidelines
- **Non-Functional Requirement Metrics**: Speed (response time), ease of use (training time), reliability (mean time to failure), robustness (failure recovery time).
- **Writing Guidelines**: Use "shall" (mandatory) vs. "should" (desirable); avoid jargon; associate rationale with requirements.

### Corresponding Assignment Exam Points
| Question Type     | Typical Topics & Examples                                    |
| ----------------- | ------------------------------------------------------------ |
| True/False        | - "Non-functional requirements are less critical than functional ones" (False)<br>- "A single non-functional requirement may generate related functional requirements" (True)<br>- "Agile development skips formal change management" (False)<br>- "Form-based specs suit alternative scenarios" (False) |
| Fill-in-the-Blank | - Detailed requirements: [system/系统]<br>- Elicitation technique: [ethnography/人种志]<br>- Change management final stage: [change implementation/变更实现] |
| Multiple Choice   | - Non-functional requirement metrics (A: Speed; B: Ease of use; C: Reliability; D: Robustness) |
| Single Choice     | - Definition of stakeholders (B: Any person affected by the system)<br>- Functional requirement example (C: Services the system should provide)<br>- Unverifiable non-functional requirement (D: "Easy to use by medical staff")<br>- Actor in use case diagram (A: Generate report – it’s a use case, not an actor)<br>- Document causing most rework (D: Requirements document) |


## Chapter 5: System Modeling
### Core Knowledge Points (English + Bilingual Key Terms)
#### 1. Basic Concepts
- **System Modeling (系统建模)**: Developing abstract models to show system perspectives (external, interaction, structural, behavioral).
- **UML (Unified Modeling Language)**: 5 core diagrams for essentials: Activity diagrams (活动图), Use case diagrams (用例图), Sequence diagrams (顺序图), Class diagrams (类图), State diagrams (状态图).

#### 2. Key Model Types
- **Context Models (上下文模型)**: Define system boundaries (边界) and dependencies with external systems (e.g., Mentcare system’s connections to other hospital systems).
- **Interaction Models (交互模型)**:
  - Use case diagrams: Show actors (human/external systems) and discrete interactions (ellipses).
  - Sequence diagrams: Show interaction order (vertical lifelines, annotated arrows, "alt" for alternatives).
- **Structural Models (结构模型)**:
  - Class diagrams: Show classes, associations (1:1, 1:*), attributes, operations.
  - Generalization (泛化): Inheritance (superclass → subclass, e.g., Doctor → Hospital Doctor).
  - Aggregation (聚集): "Whole-part" relationship (diamond notation, e.g., Patient Record → Patient + Consultations).
- **Behavioral Models (行为模型)**:
  - Activity diagrams: Data-driven (process steps + data flow; solid bars for parallel activities).
  - State diagrams: Event-driven (system states + transitions, e.g., microwave oven’s "Waiting" → "Full power").
- **Model-Driven Architecture (MDA)**: 3 models → CIM (Computation Independent Model) → PIM (Platform Independent Model/平台无关模型) → PSM (Platform Specific Model); transformations may need human intervention (CIM→PIM).

### Corresponding Assignment Exam Points
| Question Type     | Typical Topics & Examples                                    |
| ----------------- | ------------------------------------------------------------ |
| True/False        | - "MDE includes model-based testing, MDA does not" (False)<br>- "Agile methods and MDA have an uneasy relationship" (True) |
| Fill-in-the-Blank | - System model dimension: [perspective/视角]<br>- System scope definition: [boundaries/边界]<br>- "Whole-part" association: [aggregation/聚集]<br>- Behavioral stimulus type: [data/数据]<br>- MDA middle model: [PIM/平台无关模型]<br>- Platform adaptation tool: [translator/转换器] |
| Multiple Choice   | - Interaction models (C: Use case diagrams; D: Sequence diagrams) |
| Single Choice     | - Non-UML diagram (A: Block diagrams)<br>- False activity diagram statement (C: "One of three parallel activities completes → diagram ends")<br>- False sequence diagram statement (D: "Error occurs before Patient info")<br>- 1-to-many class relationship (B: Patient → Consultation)<br>- False generalization statement (B: "Doctor has Staff # attribute" – subclass Hospital Doctor has it)<br>- Event-driven modeling diagram (B: State diagram)<br>- MDA transformation needing human intervention (A: CIM→PIM) |


## 1. English-Chinese Bilingual Glossary (Chapters 4-5)
| Category                 | English Term                      | Chinese Term | Assignment Relevance                    |
| ------------------------ | --------------------------------- | ------------ | --------------------------------------- |
| Requirements Engineering | User requirements                 | 用户需求     | 填空题考点（与system requirements对应） |
|                          | System requirements               | 系统需求     | 填空题核心答案                          |
|                          | Stakeholders                      | 干系人       | 单选题定义考点                          |
|                          | Ethnography                       | 人种志       | 需求抽取技术填空题                      |
|                          | Change implementation             | 变更实现     | 变更管理流程填空题                      |
|                          | Non-functional requirements (NFR) | 非功能需求   | 判断题/多选题考点                       |
| System Modeling          | System boundaries                 | 系统边界     | 上下文模型填空题                        |
|                          | Aggregation                       | 聚集         | 结构模型关联类型填空题                  |
|                          | Generalization                    | 泛化         | 类图继承关系单选题                      |
|                          | Sequence diagram                  | 顺序图       | 交互模型判断题/单选题                   |
|                          | State diagram                     | 状态图       | 行为模型单选题                          |
| MDA                      | PIM (Platform Independent Model)  | 平台无关模型 | MDA三层模型填空题                       |
|                          | Translator                        | 转换器       | MDA平台适配填空题                       |


## 2. Mock Test (Chapters 4-5)
### Test Information
- Total Questions: 15 (5 True/False, 5 Fill-in-the-Blank, 3 Multiple Choice, 2 Single Choice)
- Total Score: 15 Points

#### Part 1: True/False (1 point each)
1. Functional requirements describe what the system should do, while non-functional requirements define constraints. ( )  
2. Ethnography is effective for discovering explicit user requirements. ( )  
3. A requirements document error leads to more rework than a coding error. ( )  
4. Aggregation in UML represents an inheritance relationship between classes. ( )  
5. PIM-to-PSM transformation in MDA requires no human intervention. ( )  

#### Part 2: Fill-in-the-Blank (1 point each)
1. Stakeholders are any person who is ______________ (affected by the system/受系统影响) in some way.  
2. The three stages of requirements change management include problem analysis, change analysis, and ______________ (change implementation/变更实现).  
3. In UML, ______________ (state diagram/状态图) is used for event-driven behavioral modeling.  
4. The "whole-part" association in class diagrams is called ______________ (aggregation/聚集).  
5. MDA defines three models: CIM, ______________ (PIM/平台无关模型), and PSM.  

#### Part 3: Multiple Choice (2 points each, partial score for incomplete selection)
1. Which of the following are non-functional requirement metrics? ( )  
   A. Response time  
   B. Number of system functions  
   C. Mean time to failure  
   D. Training time for users  

2. Which diagrams belong to UML core diagrams? ( )  
   A. Activity diagrams  
   B. Block diagrams  
   C. Use case diagrams  
   D. Sequence diagrams  

3. Which are requirements elicitation techniques? ( )  
   A. Interviewing  
   B. Ethnography  
   C. Use case modeling  
   D. Prototyping  

#### Part 4: Single Choice (1 point each)
1. Which statement about generalization is true? ( )  
   A. Subclasses inherit attributes/operations from superclasses  
   B. It represents a "whole-part" relationship  
   C. It is denoted by a diamond in UML  
   D. Superclasses add specific attributes to subclasses  

2. Why is requirements validation critical? ( )  
   A. It reduces coding time  
   B. Errors here cause the most extensive rework  
   C. It simplifies change management  
   D. It ensures compliance with coding standards  

### Mock Test Answer Key
#### Part 1: True/False
1. √  
2. × (Ethnography discovers implicit requirements)  
3. √  
4. × (Aggregation = whole-part; generalization = inheritance)  
5. × (CIM→PIM needs human intervention)  

#### Part 2: Fill-in-the-Blank
1. affected by the system  
2. change implementation  
3. state diagram  
4. aggregation  
5. PIM  

#### Part 3: Multiple Choice
1. A, C, D (B is a functional requirement metric)  
2. A, C, D (B is not a UML diagram)  
3. A, B, D (C is a specification method)  

#### Part 4: Single Choice
1. A  
2. B  


## Review Suggestions
1. Focus on **UML diagram distinctions**: Master the purpose of each core diagram (e.g., activity = process flow; sequence = interaction order; state = event response).  
2. Memorize **key processes**: Requirements engineering workflow, change management stages, MDA model transformations.  
3. Differentiate **critical concepts**: Functional vs. non-functional requirements, generalization vs. aggregation, user vs. system requirements.  
4. Practice with assignment questions: Link each question to the corresponding knowledge point (e.g., "unverifiable NFR" → guideline for writing NFRs).

Would you like me to create a **UML diagram cheat sheet** (English + Chinese annotations) summarizing core symbols and use cases for quick review?