# Software Engineering (Chapters 1-8) Final Exam Paper
Total Score: 100 Points | Time Limit: 120 Minutes


## Part 1: Objective Questions (45 Points)
### 1. True/False (1 point each, 5 points)
1. Generic software products' specifications are owned by customers. ( )
2. The waterfall model is suitable for projects with frequently changing requirements. ( )
3. Pair programming in XP discourages refactoring. ( )
4. Non-functional requirements are less critical than functional requirements. ( )
5. State diagrams belong to UML structural diagrams. ( )


### 2. Single Choice (2 points each, 10 points)
1. Which of the following is NOT a benefit of prototyping (Chapter 2 PPT)?
   A. Discover requirement errors
   B. Verify design feasibility
   C. Replace the final system
   D. Get new user requirements

2. Which Scrum role prioritizes the product backlog (Chapter 3)?
   A. Scrum Master
   B. Product Owner
   C. Project Manager
   D. Developer

3. Which UML diagram describes event-driven state transitions (Chapter 5)?
   A. Class diagram
   B. Sequence diagram
   C. State diagram
   D. Use case diagram

4. Which architectural pattern separates presentation, interaction, and data (Chapter 6)?
   A. Client-Server
   B. MVC
   C. Layered
   D. Pipe and Filter

5. "Are we building the right product?" corresponds to which V&V activity (Chapter 8)?
   A. Verification
   B. Validation
   C. Testing
   D. Inspection


### 3. Multiple Choice (3 points each; partial credit: 1 point for incomplete correct selection; 0 points for wrong selection, 12 points)
1. Which are fundamental Software Engineering activities (Chapter 1)?
   A. Specification
   B. Design & Development
   C. Validation
   D. Evolution

2. Which are core Extreme Programming (XP) practices (Chapter 3)?
   A. Refactoring
   B. Pair programming
   C. Test-first development
   D. Daily Scrum

3. Which UML diagrams belong to behavioral diagrams (Chapter 5)?
   A. Activity diagram
   B. State diagram
   C. Sequence diagram
   D. Class diagram

4. Which stages belong to development testing (Chapter 8)?
   A. Unit testing
   B. Component testing
   C. System testing
   D. Beta testing


### 4. Fill-in-the-Blank (1 point each, 8 points)
1. Software Engineering is an engineering discipline concerned with all aspects of ______ production (Chapter 1).
2. The three core software process models include waterfall, incremental development, and ______ (Chapter 2).
3. A fixed-time iteration in Scrum is called a ______ (Chapter 3).
4. ______ is a requirements elicitation technique involving immersive user observation (Chapter 4).
5. The "whole-part" relationship in class diagrams is called ______ (Chapter 5).
6. ______ refers to the architectural abstraction for complex enterprise systems (Chapter 6).
7. An object in OOD consists of ______ and operations (Chapter 7).
8. ______ testing in TDD checks for new bugs after code changes (Chapter 8).


### 5. Matching (2 points each, 10 points)
Match architectural patterns to their typical application scenarios:
1. MVC                ( ) A. Distributed systems with service providers and users
2. Client-Server      ( ) B. Web systems separating presentation, interaction, and data
3. Layered            ( ) C. Data-intensive systems with a central repository
4. Repository         ( ) D. Systems requiring multi-level security
5. Pipe and Filter    ( ) E. Data-processing systems with sequential transformations


## Part 2: Short Answer Questions (20 Points)
(Answer 2 questions below; 10 points each)
1. Explain the concept and benefits of software prototyping (Chapter 2).
2. Explain the concepts of verification and validation, and their key difference (Chapter 8).


## Part 3: Comprehensive Case Study (35 Points)
### Background
Mentcare is a mental health clinic system that supports:
- Centralized patient record management (hospital server)
- Offline access to records (laptops for home visits)
- Compliance with patient data confidentiality laws
- Synchronization between local (laptop) and central data

### Tasks
1. **Requirements Analysis (10 points)**  
   Identify 2 functional requirements (FRs) and 2 non-functional requirements (NFRs) for Mentcare, and explain why each NFR is critical for mental health services.

2. **Architectural Design (10 points)**  
   Propose a suitable architectural pattern for Mentcare, describe its structure, and justify your choice based on the system’s characteristics.

3. **System Modeling (10 points)**  
   Describe the sequence of interactions for the scenario: *"A nurse downloads a patient’s record to a laptop, edits treatment notes offline, and synchronizes data back to the central server."*

4. **Testing Scenario (5 points)**  
   Design 1 release test scenario for Mentcare’s "offline data synchronization" function (specify preconditions, test steps, and expected results).


---

# Final Review Key Points (Aligned with the Exam Paper)
### 1. Objective Questions Focus
- **True/False**: Review basic concepts (software product ownership, process model applicability, XP practices, requirement criticality, UML diagram categories).
- **Single Choice**: Master PPT core content (prototyping benefits, Scrum roles, UML diagram purposes, architectural pattern features, V&V definitions).
- **Multiple Choice**: Memorize fundamental SE activities, XP practices, behavioral UML diagrams, and development testing stages.
- **Fill-in-the-Blank**: Recite key terms (SE definition, process models, Scrum iterations, requirements elicitation, UML relationships, architectural abstraction, OOD object composition, TDD testing types).
- **Matching**: Link architectural patterns to their application scenarios (MVC for web systems, Client-Server for distributed systems, etc.).


### 2. Short Answer Questions Focus
- **Software Prototyping**:  
  Concept: An initial system version for demonstrating concepts/design options.  
  Benefits: (1) Help users evaluate system support; (2) Discover requirement strengths/weaknesses; (3) Reveal requirement errors/omissions; (4) Verify design feasibility.
- **Verification vs. Validation**:  
  - Verification: "Are we building the product right?" → Check compliance with stated requirements.  
  - Validation: "Are we building the right product?" → Ensure alignment with customer expectations.  
  - Key difference: Verification focuses on specification compliance; validation focuses on user needs.


### 3. Comprehensive Case Study Focus
- **Requirements**: Link FRs (e.g., offline record download) to NFRs (e.g., confidentiality for sensitive patient data).
- **Architecture**: Propose a hybrid pattern (e.g., Layered + Client-Server) and justify with system needs (offline access + centralized storage).
- **Modeling**: Outline sequence steps with actor-system interactions (authentication → download → offline edit → synchronization).
- **Testing**: Design measurable scenarios (preconditions → steps → expected results) covering both functional (synchronization success) and non-functional (data integrity) requirements.