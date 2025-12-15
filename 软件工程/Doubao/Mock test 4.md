# 2025秋《软件工程》(双语)期末模拟题
## 一、客观题（共60分）
### （一）判断题（每题1分，共10分）
1. Software engineering is intended to support both professional software development and individual programming.（ ）
2. The waterfall model is a linear sequential software process model where each phase must be completed before the next phase begins.（ ）
3. Agile methods are equally suitable for small-sized, medium-sized, and large-sized software products.（ ）
4. Testing can only show the presence of errors, not their absence.（ ）
5. Activity diagrams and sequence diagrams are both classified as UML interaction models.（ ）
6. Refactoring the system architecture is usually less expensive than refactoring individual components.（ ）
7. Design patterns are mainly associated with object-oriented design.（ ）
8. Legacy systems typically have complete and clear system specifications.（ ）
9. The dependability of systems is usually less important than their detailed functionality.（ ）
10. For black-box testing, no knowledge of the internal system working mechanism is required.（ ）

### （二）单选题（每题2分，共30分）
1. Which of the following is not included in professional software?（ ）
A. Programs
B. Associated documentation
C. Personal programming notes
D. Configuration data
2. Incremental delivery is not suitable for which of the following situations?（ ）
A. Customers are eager to gain value from the system
B. Initial requirements are unclear
C. The new system is intended to completely replace an existing system without intermediate use
D. It is easy to incorporate changes into the system
3. In a Scrum project, who is responsible for arranging **daily meetings** and tracking work backlogs?（ ）
A. Product owner
B. Scrum master
C. Development team members
D. Stakeholders
4. Which of the following belongs to functional requirements?（ ）
A. System response time
B. Services the system should provide
C. System security
D. System reliability
5. In a class diagram, which of the following represents a 1-to-many relationship?（ ）
A. Consultant --- Patient (1 : 1.*)
B. Patient --- Consultation (1 : 1)
C. Condition --- Patient (1 : 1)
D. Consultation --- Medication (1 : 1..3)
6. If a system requires data to flow between components for sequential processing, which architectural pattern should be adopted?（ ）
A. Layered pattern
B. Repository pattern
C. Pipe and Filter pattern
D. Client-Server pattern
7. For the statement "Flight CA1842 arrived", which identification of object, attribute, and operation is correct?（ ）
A. Object: CA1842; Attribute: Flight; Operation: arrived
B. Object: Flight; Attribute: CA1842; Operation: arrived
C. Object: arrived; Attribute: CA1842; Operation: Flight
D. Object: Flight; Attribute: arrived; Operation: CA1842
8. Which statement about V & V (Verification and Validation) is incorrect?（ ）
A. Verification and validation are not the same concept
B. Software verification checks whether the software meets stated requirements
C. The goal of software validation is to ensure the software meets the customer's expectations
D. Validation focuses on "Are we building the product right?"
9. Which of the following is not a type of software maintenance?（ ）
A. Fault repairs
B. Environmental adaptation
C. Code refactoring
D. Functionality addition
10. Which of the following is not a dependability attribute?（ ）
A. Availability
B. Usability
C. Safety
D. Security
11. Which of the following does not belong to the classification of software reuse by size?（ ）
A. Module reuse
B. Component reuse
C. Application reuse
D. System reuse
12. Which of the following is not a success criterion for project management?（ ）
A. Delivering software ahead of schedule regardless of cost
B. Delivering software that meets customer expectations
C. Maintaining a well-functioning development team
D. Keeping costs within budget
13. Which activity in the software testing process cannot be automated?（ ）
A. Design test cases
B. Prepare test data
C. Run program with test data
D. Compare results to test cases
14. Which of the following is a requirements validation technique?（ ）
A. Requirements elicitation
B. Prototyping
C. Requirements analysis
D. Requirements specification
15. Which model is part of MDA (Model-Driven Architecture) besides CIM and PSM?（ ）
A. SIM
B. PIM
C. TIM
D. MIM

### （三）多选题（每题3分，共15分）
1. Which of the following are key issues affecting many types of software?（ ）
A. Heterogeneity
B. Business and social change
C. Security and trust
D. Scale
2. Which of the following are extreme programming practices?（ ）
A. Pair programming
B. Refactoring
C. Test-first development
D. Incremental planning
3. Which UML diagrams belong to interaction modeling?（ ）
A. Sequence diagrams
B. State diagrams 0
C. Use case diagrams
D. Activity diagrams 01
4. Which views are included in Krutchen's 4+1 view model of software architecture?（ ）
A. Logical view
B. Process view
C. Development view
D. Physical view
5. Which of the following are elements of a legacy system?（ ）
A. System hardware
B. Support software
C. Application software
D. Application data

### （四）填空题（每题1分，共5分）
1. Requirements engineering includes three key activities: elicitation and analysis, ___________, and validation.
2. The output of the architectural design process is an architectural model that describes how the system is organized as a set of communicating ___________.
3. The three test stages are: development testing, ___________ testing, and user testing.
4. TDD is an approach that interleaves ___________ and code development incrementally.
5. There are three types of interface errors: interface misuse, ___________, and timing errors.

## 二、简答题（每题10分，共20分）
1. Explain the concept and benefits of software prototyping.
2. Explain the content of Agile manifesto.

## 三、综合题（共20分）
Please introduce the "Mental Health Patient Information System (Mentcare)" in detail, including the following aspects:
(1) A detailed introduction to the Mentcare system;
(2) A detailed introduction to Mentcare's context models;
(3) A detailed introduction to Mentcare's interaction models;
(4) A detailed introduction to Mentcare's structural models.


# 参考答案
## 一、客观题
### （一）判断题
1. ×  2. √  3. ×  4. √  5. √  6. ×  7. √  8. ×  9. ×  10. √

### （二）单选题
1. C  2. C  3. B  4. B  5. A  6. C  7. B  8. D  9. C  10. B  11. A  12. A  13. A  14. B  15. B

### （三）多选题
1. ABCD  2. ABCD  3. ACD  4. ABCD  5. ABCD

### （四）填空题
1. specification / 规格说明
2. components / 构件/组件
3. release / Release / 发布
4. testing / 测试
5. interface misunderstanding / Interface misunderstanding / 接口误解

## 二、简答题
1. **Concept of software prototyping**: A prototype is an initial version of a system used to demonstrate concepts and try out design options. It is not a complete system but a simplified version that focuses on key functions or interfaces to convey the core characteristics of the intended system.
**Benefits**:
- Allows potential users to directly experience how the system supports their work, helping them better understand the system's value.
- Helps users and developers discover new requirements, identify strengths and weaknesses of the software, and propose targeted improvements.
- Reveals errors, omissions, or ambiguities in initial requirements during the prototyping process, reducing the risk of late-stage requirement changes.
- Enables design experiments during the system design phase to verify the feasibility of proposed design schemes, avoiding blind design.

2. **Content of Agile manifesto**: Issued by leading developers of agile methods, the manifesto emphasizes valuing the following core principles through practical exploration:
- Individuals and interactions over processes and tools: Prioritize effective communication and collaboration among team members over rigid processes and tool dependence.
- Working software over comprehensive documentation: Focus on delivering functional software that can be used, rather than pursuing exhaustive documentation.
- Customer collaboration over contract negotiation: Advocate continuous cooperation with customers throughout the development process, rather than relying solely on fixed contracts.
- Responding to change over following a plan: Emphasize the ability to flexibly adapt to requirement changes, rather than rigidly adhering to the initial plan.
The manifesto also clarifies that while the items on the right have value, the items on the left are more valued in agile development.

## 三、综合题
### (1) Detailed introduction to the Mentcare system
The Mental Health Patient Information System (Mentcare) is a professional software system designed to manage and process mental health patient-related information. Its core purpose is to support medical staff (such as doctors, nurses, and medical receptionists) in efficiently completing work such as patient information management, consultation records, diagnosis and treatment plans, and report generation. The system covers the entire process of mental health services, from patient registration, information entry, consultation diagnosis, to follow-up management, realizing the standardized and informatized management of patient data. It not only improves the work efficiency of medical institutions but also ensures the accuracy, completeness, and security of patient information, providing strong support for clinical decision-making and medical quality improvement. The system needs to meet the functional requirements of multiple roles and comply with relevant medical information management specifications and data security regulations.

### (2) Mentcare's context models
Mentcare's context models describe the boundaries of the system and its interactions with external entities (other systems or users), clarifying "what is part of the system" and "what is external to the system".
- **System boundaries**: The core scope of Mentcare includes patient information management modules (registration, query, modification, storage), consultation and diagnosis modules, treatment plan management, report generation, and user permission control. Functions such as hospital financial settlement and medical equipment management that are not directly related to mental health patient diagnosis and treatment information management are excluded from the system boundaries.
- **External entities and interactions**:
  - Medical staff (doctors, nurses, medical receptionists): Input patient information, record consultation content, update treatment plans, and query relevant data through the system.
  - Patients: Indirectly interact with the system through medical staff (such as providing personal information and medical history), and some authorized functions (such as viewing personal basic information) may be provided.
  - Hospital information system (HIS): Realize data interaction, such as synchronizing patient basic registration information and medical record number.
  - Laboratory testing system: Obtain patient laboratory test results to assist in diagnosis and treatment decisions.
  - Drug management system: Query drug information and verify the rationality of prescribed medications.

### (3) Mentcare's interaction models
Interaction models describe the interaction processes between different entities (users, system components, external systems) in Mentcare, mainly represented by UML sequence diagrams, use case diagrams, and activity diagrams.
- **Use case diagrams**: Identify key actors (doctors, nurses, medical receptionists, etc.) and their corresponding use cases. For example, the "doctor" actor includes use cases such as viewing patient records, editing diagnosis results, formulating treatment plans, and generating medical reports; the "medical receptionist" actor includes use cases such as patient registration, information entry, and appointment scheduling.
- **Sequence diagrams**: Detail the interaction sequence between objects in a specific use case. For example, in the "view patient information" use case, the sequence is: Medical Receptionist initiates a ViewInfo (PID) request → The system calls the authorization module to verify permissions (authorize (Info, UID)) → If authorization is successful, the system queries the Mentcare database (D: Mentcare-DB) → The database returns patient information → The system displays the information to the medical receptionist; if authorization fails, the system returns an "Error (no access)" prompt.
- **Activity diagrams**: Describe the workflow of complex business processes, such as the patient consultation process: Patient registration → Doctor consultation → Conduct necessary inspections → Diagnosis → Formulate treatment plan → Record medical records → Generate follow-up reminders.

### (4) Mentcare's structural models
Structural models describe the internal composition and relationships of Mentcare, mainly represented by UML class diagrams and component diagrams.
- **Class diagrams**:
  - Core classes: Patient (attributes: PID, name, age, medical history, etc.; operations: updatePersonalInfo()), Doctor (attributes: staff ID, name, specialty, etc.; operations: diagnose(), prescribeTreatment()), Consultation (attributes: consultation ID, date, content, diagnosis result, etc.; operations: recordConsultation()), Medication (attributes: drug ID, name, dosage, usage, etc.), Hospital (attributes: hospital ID, name, address, etc.).
  - Relationships between classes:
    - Patient and Consultation: 1-to-many (a patient can have multiple consultations).
    - Doctor and Consultation: 1-to-many (a doctor can conduct multiple consultations).
    - Doctor and Medication: 1-to-many (a doctor can prescribe multiple medications).
    - Patient and Condition: 1-to-many (a patient can have multiple diagnosed conditions).
- **Component diagrams**: Divide the system into multiple functional components and clarify their dependencies. Core components include:
  - User interface component: Responsible for interacting with medical staff (input and output of information).
  - Permission management component: Handle user login, authorization, and permission control.
  - Patient information management component: Manage the addition, deletion, modification, and query of patient basic information.
  - Consultation and diagnosis component: Support consultation record entry, diagnosis result management, etc.
  - Database access component: Responsible for interacting with the backend database to realize data storage and query.
  - Report generation component: Generate medical reports, statistical reports, etc., according to requirements.


# 重点知识梳理
## 1. 软件工程基础（第1章）
- Core concepts: Professional software composition (programs, documentation, configuration data), differences between generic and customized products, four key issues (heterogeneity, business and social change, security and trust, scale).
- Key principles: Software engineering covers specification, design and development, validation, and evolution; professional responsibility (confidentiality, competence, intellectual property rights, computer misuse).

## 2. 软件过程（第2章）
- Process models: Waterfall model (linear sequential), incremental development (iterative delivery of increments), integration and configuration (based on software reuse).
- Core activities: Design (architectural design, database design, interface design, component design), debugging (finding and correcting faults), V & V (testing as the core activity), three-stage testing (component testing, system testing, customer testing).
- Key technologies: Prototyping (concept and benefits), incremental delivery (applicable scenarios), refactoring (improving program structure), change management (change anticipation, change tolerance).

## 3. 敏捷开发（第3章）
- Agile manifesto: Core values and principles.
- Extreme Programming (XP) practices: Pair programming, refactoring, test-first development, incremental planning.
- Scrum framework: Roles (Scrum master, product owner, development team), backlog (to-do list), daily meetings, sprint.
- Applicability: Suitable for small and medium-sized products, custom systems; less suitable for large-scale systems.

## 4. 需求工程（第4章）
- Core concepts: User requirements vs system requirements, functional requirements (services provided by the system) vs non-functional requirements (reliability, security, response time, etc.).
- Key activities: Elicitation and analysis (interviewing, observation, ethnography), specification, validation (reviews, prototyping, test-case generation).
- Requirements management: Change management process (problem analysis, change analysis and costing, change implementation).

## 5. 系统建模（第5章）
- UML diagrams: Use case diagrams (actors and use cases), sequence diagrams (interaction sequence), class diagrams (classes and relationships), activity diagrams (workflow), state diagrams (event-driven behavior).
- Modeling perspectives: External perspective, interaction perspective, structural perspective, behavioral perspective.
- MDA: Three abstract models (CIM, PIM, PSM).

## 6. 架构设计（第6章）
- Architectural abstraction levels: Architecture in the small, architecture in the large.
- 4+1 view model: Logical view, process view, development view, physical view (linked by use cases/scenarios).
- Common architectural patterns: Layered pattern, Repository pattern, Client-Server pattern, Pipe and Filter pattern.

## 7. 设计与实现（第7章）
- Object-oriented design: Objects (data + operations), interfaces (specification without data representation details).
- Design patterns: Four essential elements (name, problem area description, solution description, consequences statement).
- Key concepts: System boundaries, software reuse (system reuse, application reuse, component reuse, object and function reuse).

## 8. 软件测试（第8章）
- Core concepts: Testing objectives (discover defects, verify functionality), V & V (verification: "building the product right"; validation: "building the right product").
- Test stages: Development testing (unit testing, component testing, system testing), release testing, user testing.
- Testing methods: Black-box testing (no internal knowledge), white-box testing (based on code).
- Key terms: Test suite, regression testing, exhaustive testing (impossible, based on subset of test cases).

## 9. 软件演化（第9章）
- Software maintenance types: Fault repairs, environmental adaptation, functionality addition.
- Legacy systems: Definition (old systems with outdated technologies), components (hardware, support software, application software, data), characteristics (expensive to change, risky to replace).

## 10. 可靠性与项目管理（第10、22章）
- Dependability attributes: Availability, reliability, safety, security.
- Project management success criteria: On-time delivery, within budget, meeting customer expectations, maintaining a good team.
- Key constraints: Budget and schedule constraints.

## 11. Mentcare系统相关
- Core models: Context models (boundaries and external interactions), interaction models (use cases, sequence diagrams, activity diagrams), structural models (class diagrams, component diagrams).
- System characteristics: Role-oriented (doctors, nurses, medical receptionists), process coverage (registration, consultation, diagnosis, treatment, follow-up).