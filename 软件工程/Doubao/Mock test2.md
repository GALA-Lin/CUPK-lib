# Software Engineering (Chapters 1-22) Final Simulation Exam Paper
Total Score: 100 Points | Time Limit: 120 Minutes


## Part 1: Objective Questions (50 Points)
### 1. True/False (1 point each, 10 points)
1. Customized software products' specifications are owned by developers. ( )
2. The waterfall model is suitable for projects with stable requirements. ( )
3. Refactoring in XP is only performed when there is an immediate need. ( )
4. Non-functional requirements are often more critical than individual functional requirements. ( )
5. Class diagrams belong to UML behavioral diagrams. ( )
6. The choice of architectural style depends on non-functional requirements. ( )
7. There is a 1:1 relationship between objects and interfaces in OOD. ( )
8. Testing can only show the presence of errors, not their absence. ( )
9. Legacy systems usually have complete and up-to-date specifications. ( )
10. Availability is one of the core dependability attributes. ( )

### 2. Single Choice (2 points each, 16 points)
1. Which of the following is NOT a fundamental Software Engineering activity (Chapter 1)?
   A. Specification
   B. Design & Development
   C. Marketing
   D. Evolution

2. Which of the following is a benefit of software prototyping (Chapter 2)?
   A. Replace the final system
   B. Verify design feasibility
   C. Reduce user participation
   D. Increase development costs

3. Which Scrum role is responsible for facilitating the process (Chapter 3)?
   A. Product Owner
   B. Scrum Master
   C. Developer
   D. Project Manager

4. Which technique involves immersive user observation for requirements elicitation (Chapter 4)?
   A. Interviewing
   B. Ethnography
   C. Prototyping
   D. Survey

5. Which UML diagram models event-driven state transitions (Chapter 5)?
   A. Sequence diagram
   B. Activity diagram
   C. State diagram
   D. Use case diagram

6. Which architectural pattern separates presentation, interaction, and data (Chapter 6)?
   A. Layered
   B. MVC
   C. Client-Server
   D. Repository

7. Which is NOT an essential element of design patterns by the Gang of Four (Chapter 7)?
   A. Name
   B. Problem description
   C. Code implementation
   D. Consequences

8. "Are we building the product right?" corresponds to which activity (Chapter 8)?
   A. Validation
   B. Verification
   C. Testing
   D. Inspection

9. Which of the following is a type of software maintenance (Chapter 9)?
   A. Environmental adaptation
   B. System replacement
   C. Prototype development
   D. Requirement elicitation

10. Which is a core dependability attribute (Chapter 10)?
    A. Usability
    B. Reliability
    C. Portability
    D. Maintainability

11. Which level of software reuse involves reusing complete systems (Chapter 15)?
    A. Component reuse
    B. Application reuse
    C. System reuse
    D. Function reuse

12. Which is a success criterion for project management (Chapter 22)?
    A. Maximize team size
    B. Deliver on time
    C. Minimize documentation
    D. Ignore budget constraints

### 3. Multiple Choice (3 points each; partial credit: 1 point for incomplete correct selection, 12 points)
1. Which are core XP practices (Chapter 3)?
   A. Pair programming
   B. Test-first development
   C. Daily Scrum
   D. Refactoring

2. Which UML diagrams belong to behavioral diagrams (Chapter 5)?
   A. Activity diagram
   B. State diagram
   C. Class diagram
   D. Sequence diagram

3. Which are development testing stages (Chapter 8)?
   A. Unit testing
   B. Component testing
   C. System testing
   D. Beta testing

4. Which are key dependability attributes (Chapter 10)?
   A. Availability
   B. Safety
   C. Security
   D. Resilience

### 4. Fill-in-the-Blank (1 point each, 8 points)
1. Software Engineering covers all aspects of ______ production (Chapter 1).
2. The three core software process models include **waterfall**, **incremental development,** and **<u>Integration and configuration</u>** (Chapter 2).
3. The four core values of the Agile Manifesto prioritize **<u>Individuals and interactions</u>** over processes and tools (Chapter 3).
4. **<u>Ethnography</u>** is a requirements elicitation technique involving immersive observation (Chapter 4).
5. The "whole-part" relationship in class diagrams is called **<u>Aggregation</u>** (Chapter 5).
6. Krutchen’s 4+1 view model includes **logical, process, development, physical views**, and **<u>use cases</u>** (Chapter 6).
7. An object in OOD consists of data and **<u>operations</u>** (Chapter 7).
8. **<u>Regression</u>** testing in TDD checks for new bugs after code changes (Chapter 8).

### 5. Matching (2 points each, 4 points)
Match UML diagrams to their purposes:
1. Use case diagram        ( ) A. Show object state transitions
2. State diagram          ( ) B. Show interactions between actors and system
3. Class diagram          ( ) C. Show static structure of classes and relationships
4. Sequence diagram        ( ) D. Show time-ordered interactions between entities


## Part 2: Short Answer Questions (20 Points)
(Answer 2 questions below; 10 points each)
1. Explain the concept and benefits of software prototyping (Chapter 2).
2. Explain the concepts of verification and validation, and their key difference (Chapter 8).


## Part 3: Comprehensive Case Study (30 Points)
### Background
Mentcare is a mental health clinic system that supports centralized patient record management, offline access for home visits, compliance with data confidentiality laws, and data synchronization between local laptops and the central server.

### Tasks
1. **Requirements Analysis (8 points)**  
   Identify 2 functional requirements (FRs) and 2 non-functional requirements (NFRs) for Mentcare, and explain why each NFR is critical.

2. **Architectural Design (8 points)**  
   Propose a suitable architectural pattern for Mentcare, describe its structure, and justify your choice.

3. **System Modeling (8 points)**  
   Describe the sequence of interactions for the scenario: *"A nurse downloads a patient’s record offline, edits treatment notes, and synchronizes data back to the central server."*

4. **Testing Scenario (6 points)**  
   Design 1 release test scenario for Mentcare’s "data synchronization" function (specify preconditions, test steps, and expected results).


---

# Simulation Exam Answer & Explanation
## Part 1: Objective Questions (50 Points)
### 1. True/False (1 point each)
| Question | Answer | Explanation                                                  |
| -------- | ------ | ------------------------------------------------------------ |
| 1        | ×      | Customized products’ specifications are owned by customers; generic products by developers (Chapter 1). |
| 2        | √      | Waterfall model is ideal for stable, unchanging requirements (Chapter 2). |
| 3        | ×      | XP refactoring is continuous, even without immediate need (Chapter 3). |
| 4        | √      | Non-functional requirements (e.g., security) often determine system usability (Chapter 4). |
| 5        | ×      | Class diagrams are structural UML diagrams (Chapter 5).      |
| 6        | √      | Architectural style choice relies on non-functional requirements (e.g., performance, security) (Chapter 6). |
| 7        | ×      | Objects and interfaces have no fixed 1:1 relationship (Chapter 7). |
| 8        | √      | Core testing principle (Edsger Dijkstra) (Chapter 8).        |
| 9        | ×      | Legacy systems rarely have complete/up-to-date specifications (Chapter 9). |
| 10       | √      | Core dependability attributes include availability, reliability, safety, security, resilience (Chapter 10). |

### 2. Single Choice (2 points each)
| Question | Answer | Explanation                                                  |
| -------- | ------ | ------------------------------------------------------------ |
| 1        | C      | Fundamental SE activities: Specification, Design & Development, Validation, Evolution (Chapter 1). |
| 2        | B      | Prototyping benefits: Verify design feasibility, discover requirement errors, get user feedback (Chapter 2). |
| 3        | B      | Scrum Master facilitates the process; Product Owner prioritizes backlog (Chapter 3). |
| 4        | B      | Ethnography involves immersive user observation (Chapter 4). |
| 5        | C      | State diagrams model event-driven state transitions (Chapter 5). |
| 6        | B      | MVC separates presentation (View), interaction (Controller), and data (Model) (Chapter 6). |
| 7        | C      | GoF design pattern elements: Name, Problem description, Solution description, Consequences (Chapter 7). |
| 8        | B      | Verification: "Are we building the product right?"; Validation: "Are we building the right product?" (Chapter 8). |
| 9        | A      | Software maintenance types: Fault repairs, Environmental adaptation, Functionality addition (Chapter 9). |
| 10       | B      | Core dependability attributes include reliability (Chapter 10). |
| 11       | C      | System reuse: Reuse complete systems (Chapter 15).           |
| 12       | B      | Project management success criteria: Deliver on time, within budget, meet customer expectations, cohesive team (Chapter 22). |

### 3. Multiple Choice (3 points each)
| Question | Answer | Explanation                                                  |
| -------- | ------ | ------------------------------------------------------------ |
| 1        | ABD    | Core XP practices: Pair programming, Test-first development, Refactoring; Daily Scrum is a Scrum practice (Chapter 3). |
| 2        | ABD    | Behavioral UML diagrams: Activity, State, Sequence; Class diagrams are structural (Chapter 5). |
| 3        | ABC    | Development testing stages: Unit, Component, System; Beta testing is user testing (Chapter 8). |
| 4        | ABCD   | Core dependability attributes: Availability, Safety, Security, Resilience (Chapter 10). |

### 4. Fill-in-the-Blank (1 point each)
| Question | Answer                        | Chapter Reference                      |
| -------- | ----------------------------- | -------------------------------------- |
| 1        | software                      | Chapter 1: SE Definition               |
| 2        | Integration and configuration | Chapter 2: Core Process Models         |
| 3        | Individuals and interactions  | Chapter 3: Agile Manifesto             |
| 4        | Ethnography                   | Chapter 4: Requirements Elicitation    |
| 5        | Aggregation                   | Chapter 5: Class Diagram Relationships |
| 6        | use cases/scenarios           | Chapter 6: Krutchen’s 4+1 View Model   |
| 7        | operations                    | Chapter 7: OOD Object Composition      |
| 8        | Regression                    | Chapter 8: TDD Benefits                |

### 5. Matching (2 points each)
| Diagram             | Answer | Explanation                                                  |
| ------------------- | ------ | ------------------------------------------------------------ |
| 1. Use case diagram | B      | Shows interactions between actors and system (Chapter 5).    |
| 2. State diagram    | A      | Shows object state transitions (Chapter 5).                  |
| 3. Class diagram    | C      | Shows static structure of classes and relationships (Chapter 5). |
| 4. Sequence diagram | D      | Shows time-ordered interactions between entities (Chapter 5). |

## Part 2: Short Answer Questions (20 Points)
### Question 1: Explain the concept and benefits of software prototyping
- **Concept**:  
  A software prototype is an initial version of a system designed to demonstrate core concepts, test design options, or validate user requirements (not the final product).

- **Benefits**:  
  1. Help users evaluate how well the system supports their work (verify practical applicability).  
  2. Discover errors, omissions, or ambiguities in initial requirements.  
  3. Verify the feasibility of technical designs (e.g., key function implementation).  
  4. Stimulate user feedback to propose new requirements.  

(Chapter 2: Software Prototyping)

### Question 2: Explain verification, validation, and their difference
- **Verification**:  
  The process of checking whether the software meets its **stated functional and non-functional requirements** (core question: "Are we building the product right?"). Example: Verifying a payment function meets the 2-second response time requirement.

- **Validation**:  
  The process of ensuring the software meets **customer expectations** (core question: "Are we building the right product?"). Example: Confirming a payment function is intuitive for target users.

- **Key Difference**:  
  Verification focuses on **compliance with predefined specifications**; validation focuses on **alignment with actual user needs** (specifications may not fully reflect user expectations).  

(Chapter 8: V&V Definition)

## Part 3: Comprehensive Case Study (30 Points)
### 1. Requirements Analysis (8 points)
- **Functional Requirements (FRs)**:  
  1. Authorized nurses can download patient records to laptops for offline access.  
  2. The system automatically synchronizes offline-edited records to the central server when the network is restored.  

- **Non-Functional Requirements (NFRs)**:  
  1. **Confidentiality**: Offline patient records are encrypted (AES-256) to prevent unauthorized access.  
     - Criticality: Mental health records are highly sensitive; non-compliance violates privacy laws and erodes patient trust.  
  2. **Data Integrity**: Synchronized records have no conflicts or data loss.  
     - Criticality: Inaccurate records may lead to incorrect treatment decisions, endangering patient safety.  

(Chapter 4: Requirement Classification)

### 2. Architectural Design (8 points)
- **Proposed Pattern**: Hybrid (Layered Architecture + Client-Server)  
- **Structure**:  
  ```
  Client Layer (Laptop)          Server Layer (Central Server)
  ┌───────────────────────────┐  ┌───────────────────────────────────┐
  │ Presentation Layer (UI)    │  │ Presentation Layer (Web Portal)  │
  ├───────────────────────────┤  ├───────────────────────────────────┤
  │ Application Layer (Sync/   │  │ Application Layer (Access Control/│
  │  Encryption Logic)         │  │  Conflict Resolution)             │
  ├───────────────────────────┤  ├───────────────────────────────────┤
  │ Data Access Layer (Local   │  │ Data Access Layer (Central DB     │
  │  DB Interface)             │  │  Interface)                       │
  └───────────────────────────┘  └───────────────────────────────────┘
                                   │
                                   ▼
                               Data Layer (Central DB)
  ```
- **Justification**:  
  1. Layered Architecture: Separates concerns (e.g., changing encryption rules only affects the Application Layer), simplifying maintenance.  
  2. Client-Server: Enables centralized data management (consistency) and offline client access (critical for home visits).  

(Chapter 6: Architectural Patterns)

### 3. System Modeling (8 points)
- **Sequence of Offline Data Synchronization**:  
  1. Nurse logs into the Mentcare client (laptop) and enters credentials for authentication.  
  2. Client sends an authentication request to the central server; server validates and returns an access token.  
  3. Nurse selects a patient record and requests offline download; client fetches encrypted data from the central DB.  
  4. Client decrypts data (with the nurse’s key) and stores it locally (re-encrypts for offline security).  
  5. Nurse edits treatment notes (e.g., "medication side effect: insomnia") while offline.  
  6. When back online, client sends a synchronization request (with updated data) to the server.  
  7. Server resolves conflicts (e.g., no concurrent edits) and merges the record into the central DB.  
  8. Server confirms successful synchronization; client updates local data to match the server.  

(Chapter 5: Sequence Diagrams)

### 4. Testing Scenario (6 points)
- **Test Scenario**: Offline Data Synchronization (Functional + Non-Functional)  
- **Preconditions**:  
  - Nurse has valid credentials; central DB contains patient "Lily’s" record (medication: anxiety pills).  
  - Laptop is connected to the network initially, then disconnected.  
- **Test Steps**:  
  1. Nurse logs in and downloads Lily’s record to the laptop.  
  2. Disable the laptop’s network (simulate offline mode).  
  3. Nurse edits Lily’s record: adds "side effect: insomnia" and saves.  
  4. Re-enable the network and trigger synchronization.  
  5. Check the central DB for the updated record.  
- **Expected Results**:  
  - Lily’s record in the central DB includes the "insomnia" note.  
  - No data loss/corruption; synchronization completes within 5 seconds.  

(Chapter 8: Release Testing)

---

# Review Key Points
## 1. Core Focus of Chapters 1-8 (Main Exam Content)
- **Chapter 1**: SE definition, software product types, fundamental activities.  
- **Chapter 2**: Process models (waterfall, incremental), prototyping (concept + benefits).  
- **Chapter 3**: Agile Manifesto, XP practices, Scrum roles.  
- **Chapter 4**: Requirement classification (functional/non-functional), elicitation techniques (ethnography).  
- **Chapter 5**: UML diagram types (structural/behavioral), core models (context/interaction/structural/behavioral).  
- **Chapter 6**: Architectural patterns (MVC/Layered/Client-Server), 4+1 view model.  
- **Chapter 7**: OOD (object = data + operations), design pattern 4 elements.  
- **Chapter 8**: Testing stages (development/release/user), V&V (verification vs validation), TDD.  

## 2. Subsequent Chapters (1-2 Questions Each)
- **Chapter 9**: Legacy systems (components, characteristics), software maintenance types.  
- **Chapter 10**: Dependability attributes (availability/reliability/safety/security/resilience).  
- **Chapter 15**: Software reuse levels (system/application/component/object and function).  
- **Chapter 22**: Project management success criteria, core activities.  

## 3. Key Tips
- **Term Memorization**: Focus on fill-in-the-blank terms (e.g., ethnography, aggregation, regression) and matching questions (UML diagrams).  
- **True/False Traps**: Master critical judgments (e.g., non-functional requirements are more critical; testing can’t prove no errors).  
- **Short Answers**: Memorize the two selected questions (prototyping, V&V) in English (exam is bilingual).  
- **Comprehensive Case**: Link Mentcare to requirements, architecture, modeling, testing—cover multiple chapters to demonstrate integrated knowledge.  

## 4. Error-Prone Points
- Confusing UML diagram categories (structural vs behavioral).  
- Mixing up verification and validation.  
- Forgetting XP/Scrum core concepts.  
- Misunderstanding architectural pattern applicability.  

Focus on these points to efficiently prepare for the exam, with priority given to Chapters 1-8 while reviewing subsequent chapters’ key terms.