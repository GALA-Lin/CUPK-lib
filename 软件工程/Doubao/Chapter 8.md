# Software Engineering (Bilingual) Review Reference: Chapter 8 (Software Testing)
## Overview
This review covers core knowledge of **Chapter 8 (Software Testing)** and aligns with the second quiz’s key exam points (fill-in-the-blank, true/false, single choice, multiple choice). Core content is presented in English with bilingual annotations for key terms, and directly maps to quiz questions for targeted review.

## Core Knowledge Points (English + Bilingual Key Terms)
### 1. Testing Fundamentals (测试基础)
#### 1.1 Testing Goals & Core Principles
- **Testing Definition**: Intended to show a program meets requirements and discover **defects (缺陷)** before deployment (Quiz Q1).
- **Key Principle**: "Testing can only show the presence of errors, not their absence" (Edsger Dijkstra) – TRUE (Quiz Q2).
- **V&V (Verification & Validation, 验证与确认)**  
  | Term                | Definition                                                   | Chinese Annotation         | Quiz Q3 Key Trap                                             |
  | ------------------- | ------------------------------------------------------------ | -------------------------- | ------------------------------------------------------------ |
  | Verification (验证) | "Are we building the product right?"; Check if software meets stated functional/non-functional requirements. | 验证“产品构建是否正确”     | Option C (Verification = meet customer expectations) is FALSE (this is Validation). |
  | Validation (确认)   | "Are we building the right product?"; Ensure software meets customer expectations. | 确认“是否构建了正确的产品” | -                                                            |
- **V&V Goal**: Establish **confidence (信心)** that software is "fit for purpose" (Quiz Q4).

#### 1.2 Inspections vs Testing (检查 vs 测试)
| Aspect             | Inspections (检查)                                           | Testing (测试)                                               | Quiz Q5/Q6 Key Points                                        |
| ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Type               | Static V&V (no software execution)                           | Dynamic V&V (requires software execution)                    | Inspections can check requirements/design/code (not only executable programs) – Q5 FALSE. |
| Incomplete Systems | No additional cost to inspect                                | Need specialized test harnesses to test partial programs     | Q6 Option B is TRUE.                                         |
| Error Interactions | No worry about error interactions (single session finds multiple errors) | Prone to error interactions                                  | Q6 Option C is TRUE.                                         |
| Strengths          | Check broad quality (standards, portability); find more defects than testing | Discover interaction/timing/performance defects (inspections do not) | Q6 Option D is FALSE (Testing is good for these defects; inspections are not). |

#### 1.3 Testing Process Model (测试过程模型)
- **Steps**: Design test cases → Prepare test data → Run program → Compare results with test cases.
- **Automation**: Only **Design test cases (设计测试用例)** cannot be automated (Quiz Q7, Option A).

#### 1.4 Testing Stages (测试阶段)
- Three high-level stages: **Development testing (开发测试)**, **Release testing (发布测试)**, User testing (用户测试) (Quiz Q8).

### 2. Development Testing (开发测试)
#### 2.1 Sub-stages of Development Testing
| Sub-stage                    | Focus                                                        | Key Term (Quiz Q9/Q10/Q11)                            |
| ---------------------------- | ------------------------------------------------------------ | ----------------------------------------------------- |
| Unit testing (单元测试)      | Test individual units (methods/object classes); cover (覆盖) all features of objects (attributes, operations, states) | Quiz Q9 (Component), Q10 (coverage), Q11 (interfaces) |
| Component testing (构件测试) | Test integrated composite components; focus on **interfaces (接口)** (access to component functions) | -                                                     |
| System testing (系统测试)    | Test the integrated system; focus on component interactions  | -                                                     |

#### 2.2 Unit Testing for Object Classes (对象类的单元测试)
- Test all operations/attributes/states of an object; use state models to test state transition sequences (e.g., Shutdown→Configuring→Running→Summarizing):
  - Reconfigure() (triggers Configuring state), reportWeather() (triggers Summarizing state) are testable (Quiz Q12: Options A, C).
  - Shutdown() (initial state, not triggered in the sequence) and powerSave() (no state transition for this method) are not testable.

#### 2.3 Test Case Design (测试用例设计)
- **Partition Testing (划分测试)**: Test boundary values + midpoint of equivalence partitions (e.g., interval [3,9] → test 2 (lower boundary-), 3 (lower boundary), 6 (midpoint), 9 (upper boundary), 10 (upper boundary+)) (Quiz Q13: Option A is optimal).
- **Black-box vs White-box Testing**:
  - Black-box: No knowledge of system internal working (TRUE).
  - White-box: Look at code to design test cases (TRUE) (Quiz Q14).

#### 2.4 Component Testing (构件测试) – Interfaces (接口)
- **Interface Types**: Parameter interfaces, shared memory interfaces, **procedural (过程) interfaces**, message passing interfaces (Quiz Q15).
- **Interface Error Types**: Interface misuse (接口误用), **interface misunderstanding (接口误解)**, timing errors (时序错误) (Quiz Q16).

### 3. Test-Driven Development (TDD, 测试驱动开发)
- **Core Characteristics**:
  - Interleave testing and code development (交织测试与代码开发).
  - Incremental code development + corresponding tests (增量开发代码+测试).
  - **Do NOT start next increment until current code passes all tests** (Quiz Q18: Option C is FALSE).
  - Applicable to both agile and plan-driven processes.
- **Key Benefit**: Regression testing (回归测试) – run test suite to check for new bugs after code changes (Quiz Q19).

## Corresponding Quiz Exam Points
| Quiz Question | Type              | Core Topic                             | Correct Answer/Key Note                                      |
| ------------- | ----------------- | -------------------------------------- | ------------------------------------------------------------ |
| 1             | Fill-in-the-blank | Testing goal                           | defects/缺陷                                                 |
| 2             | True/False        | Testing principle                      | TRUE (Testing only shows errors exist, not absence)          |
| 3             | Single Choice     | V&V definition                         | C (Verification ≠ meet customer expectations – this is Validation) |
| 4             | Fill-in-the-blank | V&V goal                               | confidence/信心                                              |
| 5             | True/False        | Inspections vs Testing scope           | FALSE (Inspections can check requirements/design; Testing needs execution) |
| 6             | Single Choice     | Inspections vs Testing characteristics | D (Testing IS good for interaction/timing/performance defects) |
| 7             | Single Choice     | Testing process automation             | A (Design test cases cannot be automated)                    |
| 8             | Fill-in-the-blank | Testing stages                         | release/发布                                                 |
| 9             | Fill-in-the-blank | Development testing sub-stages         | Component/构件                                               |
| 10            | Fill-in-the-blank | Unit testing for object classes        | coverage/覆盖                                                |
| 11            | Fill-in-the-blank | Component testing focus                | interfaces/接口                                              |
| 12            | Multiple Choice   | State transition & method testing      | A (reconfigure()), C (reportWeather())                       |
| 13            | Single Choice     | Partition testing (boundary values)    | A (2,3,4,6,8,9,10 – covers boundaries + midpoint)            |
| 14            | True/False        | Black-box vs White-box testing         | TRUE                                                         |
| 15            | Fill-in-the-blank | Interface types                        | Procedural/过程                                              |
| 16            | Fill-in-the-blank | Interface error types                  | interface misunderstanding/接口误解                          |
| 18            | Single Choice     | TDD principles                         | C (Cannot start next increment before current tests pass)    |
| 19            | Fill-in-the-blank | TDD benefit (regression testing)       | regression/回归                                              |

## Key Review Suggestions
1. **V&V Distinction**: Memorize the core difference between Verification ("right product") and Validation ("product right") – this is a frequent single-choice trap.
2. **Development Testing Stages**: Master the focus of each sub-stage (Unit = functionality, Component = interfaces, System = interactions) – key fill-in-the-blank points.
3. **Test Case Design**: Focus on partition testing (boundary + midpoint values) – the most common single-choice question for test case selection.
4. **Inspections vs Testing**: Remember inspections are static (no execution) and testing is dynamic (execution required); testing is better for interaction/timing/performance defects.
5. **TDD Core Rules**: Do not start next increment until current code passes all tests; regression testing is a key benefit – critical for true/false/single-choice questions.