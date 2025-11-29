# Software Engineering (Bilingual) Review Reference: Chapter 1-2
## Overview
This review covers core knowledge from Chapter 1 (Introduction) and Chapter 2 (Software Processes), aligned with assignment questions (true/false, fill-in-the-blank, multiple choice, single choice) and key exam points. All key content is presented in English (bilingual hints where necessary for clarity).


## Chapter 1: Introduction
### Key Knowledge Points (English)
- **Definition of Software Engineering (SE)**: An engineering discipline concerned with all aspects of software production (from specification to maintenance).
- **Software Product Types**:
  - Generic products: Stand-alone systems for general markets (specification owned by developers).
  - Customized products: Commissioned for specific customers (specification owned by customers).
- **Fundamental SE Activities**: Specification → Design & Development → Validation → Evolution/Maintenance.
- **Software Failure Causes**: Increasing system complexity; failure to adopt software engineering methods.
- **General Issues Affecting Software**: Heterogeneity, business & social change, security & trust, scale.
- **Professional Software Components**: Programs, associated documentation, libraries, configuration data (all four are required).
- **Application Types**: Data collection systems (e.g., wilderness weather station), embedded control systems, batch processing systems, etc.
- **Web-based SE Features**: Conventional SE fundamentals still apply; software reuse and incremental development are dominant approaches.
- **Professional Responsibilities**: Confidentiality, competence, intellectual property rights, computer misuse.

### Corresponding Assignment Exam Points
| Question Type     | Typical Topics & Examples                                    |
| ----------------- | ------------------------------------------------------------ |
| True/False        | - "Universal SE notations/methods exist" (False)<br>- "SE supports individual programming" (False)<br>- "SE focuses solely on design/implementation" (False) |
| Fill-in-the-Blank | - Software failure factors: [software engineering/SE/软件工程]<br>- SE activities: [software evolution/software maintenance/软件演化/维护]<br>- Customized product spec owner: [customer/客户]<br>- General issue affecting software: [scale/规模]<br>- Professional responsibility: [competence/工作能力] |
| Multiple Choice   | - Components of professional software (A: programs; B: documentation; C: libraries; D: configuration data) |
| Single Choice     | - Key factor for SE methods (B: Type of application being developed)<br>- False statement about Web-based SE (C: Conventional SE ideas no longer apply)<br>- Application type of wilderness weather station (A: Data collection systems) |


## Chapter 2: Software Processes
### Key Knowledge Points (English)
- **Software Process Models**:
  - Waterfall model: Plan-driven, sequential phases (requirements → design → implementation → testing → maintenance); suitable for stable requirements/large engineering projects.
  - Incremental development: Interleaved specification/development/validation; feedback-driven; benefits include reduced change costs and rapid delivery.
  - Integration & configuration: Reuse-based (existing components + integrating framework); standard for business systems.
- **Process Description Components**: Activities, ordering of activities, products, roles, pre-conditions, post-conditions.
- **Requirements Engineering**: Process of defining services/constraints; outputs an agreed requirements document.
- **Design & Implementation**: Converts specification to executable system; debugging = finding + correcting program faults.
- **Software Validation (V&V)**:
  - Testing is the most common V&V activity.
  - 3-stage testing: Component testing → System testing → Customer/Beta testing (beta testing: selected users try software).
- **Coping with Change**:
  - Change anticipation (e.g., prototyping) + Change tolerance (e.g., incremental delivery).
  - Refactoring: Improves program structure to prevent degradation.
- **Process Improvement**:
  - Process maturity approach (SEI 5 levels: Initial → Managed → Defined → Quantitatively managed → Optimizing).
  - Agile approach: Iterative, low-overhead, responsive to changes.

### Corresponding Assignment Exam Points
| Question Type     | Typical Topics & Examples                                    |
| ----------------- | ------------------------------------------------------------ |
| True/False        | - "Development & maintenance are separate processes" (False)<br>- "High-priority requirements in early increments get most testing" (False) |
| Fill-in-the-Blank | - Process activity element: [ordering/次序]<br>- Process model: [Integration and configuration/集成和配置]<br>- Debugging: [Debugging/调试]<br>- Core V&V activity: [testing/system testing/测试]<br>- 3-stage testing: [System testing/系统测试]<br>- Change tolerance method: [Change tolerance/变更容忍]<br>- Coping with change: [Incremental delivery/增量式交付]<br>- Improve program structure: [Refactoring/重构]<br>- Process improvement approach: [agile/敏捷]<br>- SEI maturity cycle: [analyze/分析]<br>- SEI maturity level: [Managed/被管理级] |
| Multiple Choice   | - Waterfall model applicable scenarios (A: Stable requirements; B: Limited changes; D: Large multi-site projects)<br>- Incremental development benefits (A: Reduced change cost; B: Faster feedback; C: Rapid delivery)<br>- Process description components (A: Pre-conditions; B: Products; C: Roles; D: Post-conditions) |
| Single Choice     | - False about Integration & configuration (A: User requirements are fully satisfied)<br>- False about software specification (B: Developers need high-level spec; users need detailed)<br>- Incremental delivery unsuitable scenario (A: Replace existing system)<br>- Beta testing participants (D: Selected users) |


## Subjective Ideological & Political Question
- **Focus**: EDA software (definition, importance); international leading EDA companies (Synopsys, Cadence, Siemens EDA); China’s gaps in EDA technology; related "chokepoint" events & reflections.
- **Requirements**: ≥2000 words; original content (no direct copying); Word file with cover (name, class, student ID); structured formatting.


## Review Suggestions
1. Prioritize memorizing core terms and their definitions (e.g., SE activities, process models, testing stages).
2. Understand the applicability of each process model (when to use waterfall vs. incremental development).
3. Master fill-in-the-blank answers—focus on key nouns/verbs from the textbook and PPT.
4. For the subjective question, collect data on EDA industry trends, Sino-US tech competition, and China’s independent innovation strategies.

# 1. English-Chinese Bilingual Glossary of Core Terms (Chapters 1-2)
| Category                | English Term                       | Chinese Term     | Key Notes (Relevance to Assignment)                  |
| ----------------------- | ---------------------------------- | ---------------- | ---------------------------------------------------- |
| Basic Concepts          | Software Engineering (SE)          | 软件工程         | 作业填空考点，软件失效的解决手段                     |
|                         | Professional Software              | 专业软件         | 多选题考点，包含程序、文档、库、配置数据             |
|                         | Generic Products                   | 通用产品         | 填空题考点，规格说明归开发者所有                     |
|                         | Customized Products                | 定制化产品       | 填空题考点，规格说明归客户所有                       |
|                         | Software Failure                   | 软件失效         | 填空题考点，原因：系统复杂度+未使用软件工程方法      |
| Software Process Models | Waterfall Model                    | 瀑布模型         | 多选题/判断题考点，适用于需求稳定的场景              |
|                         | Incremental Development            | 增量式开发       | 单选题/多选题考点，优势：降低变更成本、快速交付      |
|                         | Integration and Configuration      | 集成和配置       | 填空题考点，基于软件复用，是商业系统的标准方法       |
| Process Activities      | Software Specification             | 软件规格说明     | 单选题考点，定义系统服务和约束的过程                 |
|                         | Software Design and Implementation | 软件设计与实现   | 单选题考点，将规格说明转化为可执行系统               |
|                         | Software Validation                | 软件确认         | 填空题考点，包含评审和测试，测试是最常用手段         |
|                         | Software Evolution / Maintenance   | 软件演化/维护    | 填空题考点，软件过程的核心活动之一                   |
| Testing & Validation    | Debugging                          | 调试             | 填空题考点，定位并修正程序错误的活动                 |
|                         | Component Testing                  | 组件测试         | 填空题考点，三阶段测试的第一阶段                     |
|                         | System Testing                     | 系统测试         | 填空题考点，三阶段测试的第二阶段                     |
|                         | Customer / Beta Testing            | 客户测试/β测试   | 单选题考点，β测试由选定用户参与                      |
| Change & Improvement    | Change Anticipation                | 变化预见         | 填空题考点，通过原型等方式提前应对变更               |
|                         | Change Tolerance                   | 变化容忍         | 填空题考点，通过增量交付实现                         |
|                         | Refactoring                        | 重构             | 填空题考点，优化程序结构以避免退化                   |
|                         | Process Maturity Approach          | 过程成熟度方法   | 填空题考点，SEI提出5级成熟度                         |
|                         | Agile Approach                     | 敏捷方法         | 填空题考点，过程改进的两大途径之一，强调迭代和低开销 |
| Others                  | Heterogeneity                      | 异构性           | 填空题考点，影响软件的四大通用问题之一               |
|                         | Scale                              | 规模             | 填空题考点，影响软件的四大通用问题之一               |
|                         | Confidentiality                    | 保密（责任）     | 填空题考点，软件工程师的职业责任之一                 |
|                         | Competence                         | 工作能力（责任） | 填空题考点，软件工程师的职业责任之一                 |


# 2. Software Engineering (Chapters 1-2) Mock Test
## Test Information
- Total Questions: 20 (10 True/False, 5 Fill-in-the-Blank, 3 Multiple Choice, 1 Single Choice, 1 Subjective Question)
- Total Score: 20 Points


### Part 1: True/False (1 point each, total 10 points)
1. Software engineering provides universal methods that are applicable to all types of software development. ( )  
2. The specification of customized software products is owned by the software developer. ( )  
3. Web-based software engineering no longer requires the fundamental principles of conventional software engineering. ( )  
4. The waterfall model is most suitable for projects with unstable and frequently changing requirements. ( )  
5. Incremental development allows customers to gain value from software earlier than the waterfall model. ( )  
6. Debugging is the same as testing, both focusing on finding program faults. ( )  
7. Beta testing is usually conducted by the software development team to verify system functions. ( )  
8. Most software systems are completely new, so development and maintenance can be treated as separate processes. ( )  
9. Refactoring aims to improve the structure of a program without changing its external functions. ( )  
10. The "Optimizing" level is the highest level in the SEI process maturity model. ( )  


### Part 2: Fill-in-the-Blank (1 point each, total 5 points)
1. The four fundamental software engineering activities are software specification, software design and development, software validation, and ______________ (软件演化/software evolution).  
2. The three core software process models introduced in the textbook are the waterfall model, incremental development, and ______________ (集成和配置/Integration and configuration).  
3. The three-stage testing process includes component testing, ______________ (系统测试/System testing), and customer testing.  
4. The two approaches to coping with changing requirements are system prototyping and ______________ (增量式交付/Incremental delivery).  
5. The SEI process maturity model has five levels: Initial, ______________ (被管理级/Managed), Defined, Quantitatively managed, and Optimizing.  


### Part 3: Multiple Choice (2 points each, partial score for incomplete selection, total 6 points)
1. Which of the following belong to the components of professional software? ( )  
   A. Computer hardware  
   B. Associated documentation  
   C. Configuration data  
   D. Reusable libraries  

2. Which of the following are the benefits of incremental development? ( )  
   A. Reducing the cost of requirement changes  
   B. Making it harder to obtain customer feedback  
   C. Delivering useful software more quickly  
   D. Improving the visibility of the development process  

3. Which of the following are included in software process descriptions? ( )  
   A. Pre-conditions of activities  
   B. Roles of participants  
   C. Outcomes of activities (products)  
   D. Market share of the software  


### Part 4: Single Choice (1 point each, total 1 point)
1. Which factor is the most significant in determining the choice of software engineering methods? ( )  
   A. The number of developers in the team  
   B. The type of application being developed  
   C. The budget of the project  
   D. The brand of development tools  


### Part 5: Subjective Ideological & Political Question (4 points)
In recent years, China has accelerated the independent research and development of key core technologies in the software field. Combined with the knowledge of software engineering and the background of "chokepoint" technologies (e.g., EDA, operating systems), answer the following questions:  
(1) What is the significance of independent innovation in software engineering for China’s digital economy?  
(2) As a software engineering learner, what abilities should you develop to contribute to the independent research and development of core software technologies?  


# 3. Mock Test Answer Key
## Part 1: True/False
1. × (No universal methods; different software requires different approaches)  
2. × (Customized products’ specification is owned by customers)  
3. × (Conventional SE fundamentals still apply to web-based software)  
4. × (Waterfall model is suitable for stable requirements)  
5. √ (Incremental delivery provides early usable software)  
6. × (Debugging = finding + correcting faults; testing focuses on finding faults)  
7. × (Beta testing is conducted by selected users, not developers)  
8. × (Development and maintenance are a continuum, not separate)  
9. √ (Refactoring improves structure without changing external functions)  
10. √ (SEI maturity model’s highest level is Optimizing)  


## Part 2: Fill-in-the-Blank
1. software evolution / 软件演化  
2. Integration and configuration / 集成和配置  
3. System testing / 系统测试  
4. Incremental delivery / 增量式交付  
5. Managed / 被管理级  


## Part 3: Multiple Choice
1. B, C, D (Hardware is not part of software; professional software includes docs, config data, libraries)  
2. A, C (Incremental development facilitates feedback and improves visibility, so B/D are wrong)  
3. A, B, C (Market share is not related to process descriptions)  


## Part 4: Single Choice
1. B (The type of application is the most significant factor, as per Chapter 1)  


## Part 5: Subjective Question (Reference Answer)
(1) **Significance of independent innovation**:  
- Avoid "chokepoint" risks: Independent software (e.g., EDA, industrial software) ensures the security of China’s industrial chain and supply chain, preventing external technical blockades.  
- Drive digital economy development: Independent software engineering technologies support the transformation of traditional industries (e.g., smart manufacturing, fintech) and promote high-quality economic growth.  
- Enhance international competitiveness: Leading software innovation helps China gain a voice in global digital governance and break the monopoly of foreign software in high-end fields.  

(2) **Abilities to develop**:  
- Solid technical foundation: Master core SE technologies (e.g., system design, software reuse, reliable system development) to lay a foundation for independent R&D.  
- Innovative thinking: Cultivate the ability to solve complex technical problems (e.g., improving software efficiency, enhancing system security) and explore new software engineering methods.  
- Strategic vision: Understand the development trends of key technologies (e.g., AI-driven software development, open-source ecology) and focus on the needs of national key industries.  
- Professional ethics: Adhere to the concept of "serving the country with technology" and ensure the reliability, security, and compliance of independently developed software.
