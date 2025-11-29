# Software Engineering Final Exam Paper Answer & Explanation


## Part 1: Objective Questions (45 Points)
### 1. True/False (1 point each)
| Question | Answer | Explanation (Chapter Reference)                              |
| -------- | ------ | ------------------------------------------------------------ |
| 1        | ×      | Generic software products’ specifications are owned by **developers** (Customized products are owned by customers) (Chapter 1: Software Product Types). |
| 2        | ×      | The waterfall model is suitable for **stable requirements**; it is not adaptable to frequent changes (Chapter 2: Software Process Models). |
| 3        | ×      | Pair programming in XP **encourages refactoring** (it serves as informal code review and simplifies code optimization) (Chapter 3: XP Practices). |
| 4        | ×      | Non-functional requirements (e.g., security, reliability) are often **more critical** than individual functional requirements (Chapter 4: Requirement Classification). |
| 5        | ×      | State diagrams belong to **behavioral UML diagrams** (structural diagrams include class/object diagrams) (Chapter 5: UML Diagram Categories). |


### 2. Single Choice (2 points each)
| Question | Answer | Explanation (Chapter Reference)                              |
| -------- | ------ | ------------------------------------------------------------ |
| 1        | C      | Prototypes are used to demonstrate concepts/validate designs; they **do not replace the final system** (Chapter 2: Benefits of Prototyping). |
| 2        | B      | The Product Owner is responsible for prioritizing the product backlog (Scrum Master facilitates the process; Project Manager oversees delivery) (Chapter 3: Scrum Roles). |
| 3        | C      | State diagrams model event-driven state transitions (e.g., "Waiting" → "Running" via a trigger) (Chapter 5: Behavioral Models). |
| 4        | B      | MVC (Model-View-Controller) separates presentation (View), user interaction (Controller), and system data (Model) (Chapter 6: Architectural Patterns). |
| 5        | B      | Validation answers "Are we building the right product?" (Verification answers "Are we building the product right?") (Chapter 8: V&V Definition). |


### 3. Multiple Choice (3 points each)
| Question | Answer | Explanation (Chapter Reference)                              |
| -------- | ------ | ------------------------------------------------------------ |
| 1        | ABCD   | The 4 fundamental SE activities are Specification, Design & Development, Validation, and Evolution (Chapter 1: SE Activities). |
| 2        | ABC    | Daily Scrum is a **Scrum practice** (not XP); core XP practices include Refactoring, Pair Programming, and Test-first Development (Chapter 3: XP vs. Scrum). |
| 3        | ABC    | Class diagrams belong to **structural diagrams**; behavioral diagrams include Activity, State, and Sequence diagrams (Chapter 5: UML Categories). |
| 4        | ABC    | Beta testing is a **user testing stage** (not development testing); development testing includes Unit, Component, and System testing (Chapter 8: Testing Stages). |


### 4. Fill-in-the-Blank (1 point each)
| Question | Answer                        | Chapter Reference                              |
| -------- | ----------------------------- | ---------------------------------------------- |
| 1        | software                      | Chapter 1: SE Definition                       |
| 2        | Integration and configuration | Chapter 2: Core Process Models                 |
| 3        | Sprint                        | Chapter 3: Scrum Terminology                   |
| 4        | Ethnography                   | Chapter 4: Requirements Elicitation Techniques |
| 5        | Aggregation                   | Chapter 5: Class Diagram Relationships         |
| 6        | Architecture in the large     | Chapter 6: Architectural Abstraction           |
| 7        | data                          | Chapter 7: OOD Object Composition              |
| 8        | Regression                    | Chapter 8: TDD Benefits                        |


### 5. Matching (2 points each)
| Pattern            | Answer | Chapter Reference                 |
| ------------------ | ------ | --------------------------------- |
| 1. MVC             | B      | Chapter 6: Architectural Patterns |
| 2. Client-Server   | A      | Chapter 6: Architectural Patterns |
| 3. Layered         | D      | Chapter 6: Architectural Patterns |
| 4. Repository      | C      | Chapter 6: Architectural Patterns |
| 5. Pipe and Filter | E      | Chapter 6: Architectural Patterns |


## Part 2: Short Answer Questions (20 Points)
### Question 1: Explain the concept and benefits of software prototyping
- **Concept**:  
  A software prototype is an initial version of a system, designed to demonstrate core concepts, test design options, or validate user requirements (rather than serve as the final product).

- **Benefits**:  
  1. Help potential users evaluate how well the system supports their work (verify practical applicability).  
  2. Enable users to identify strengths/weaknesses of initial requirements and propose new needs.  
  3. Reveal errors (e.g., logical conflicts) and omissions in system requirements during prototype development.  
  4. Allow design experiments to check the feasibility of a proposed technical solution.  

(Chapter 2: Software Prototyping)


### Question 2: Explain verification, validation, and their difference
- **Verification**:  
  The process of checking whether the software meets its **stated functional and non-functional requirements** (core question: "Are we building the product right?"). For example: Verifying if a payment function complies with the specified 2-second response time.

- **Validation**:  
  The process of ensuring the software meets **customer expectations** (core question: "Are we building the right product?"). For example: Confirming if the payment function is intuitive enough for target users.

- **Key Difference**:  
  Verification focuses on **compliance with predefined specifications**; validation focuses on **alignment with actual user needs** (specifications may not fully reflect user expectations).  

(Chapter 8: V&V Definition)


## Part 3: Comprehensive Case Study (35 Points)
### 1. Requirements Analysis (10 points)
- **Functional Requirements (FRs)**:  
  1. Allow authorized nurses to download patient records to laptops for offline access.  
  2. Support automatic synchronization of offline-edited records to the central server (when network is restored).  

- **Non-Functional Requirements (NFRs)**:  
  1. **Confidentiality**: Offline patient records must be encrypted (AES-256) to prevent unauthorized access.  
     - Criticality: Mental health records are highly sensitive; unencrypted data could violate privacy laws and erode patient trust.  
  2. **Data Integrity**: Synchronized records must not have conflicts (e.g., concurrent edits) or data loss.  
     - Criticality: Inaccurate records could lead to incorrect treatment decisions, compromising patient safety.  

(Chapter 4: Requirement Classification)


### 2. Architectural Design (10 points)
- **Proposed Pattern**: Hybrid (Layered Architecture + Client-Server)  
- **Structure**:  
  ```
  Client Layer (Laptop)          Server Layer (Central Hospital Server)
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
                               Data Layer (Central Patient DB)
  ```
- **Justification**:  
  1. **Layered Architecture**: Separates concerns (e.g., changing encryption rules only affects the Application Layer), simplifying maintenance.  
  2. **Client-Server**: Enables centralized data management (consistency) and offline client access (critical for home visits).  

(Chapter 6: Architectural Patterns)


### 3. System Modeling (10 points)
Sequence of "Offline Record Synchronization":  
1. Nurse logs into the Mentcare client (laptop) and enters credentials for authentication.  
2. Client sends an authentication request to the central server; server validates and returns an access token.  
3. Nurse selects a patient record and requests offline download; client fetches encrypted data from the central DB.  
4. Client decrypts the data (with the nurse’s key) and stores it locally (re-encrypts for offline security).  
5. Nurse edits treatment notes (e.g., "medication side effect: dizziness") while offline.  
6. When back online, client sends a synchronization request (with updated data) to the server.  
7. Server resolves conflicts (e.g., no concurrent edits) and merges the updated record into the central DB.  
8. Server confirms successful synchronization; client updates local data to match the server.  

(Chapter 5: Sequence Diagrams)


### 4. Testing Scenario (5 points)
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
  - No data loss/corruption occurs; synchronization completes within 5 seconds.  

(Chapter 8: Release Testing)