# Software Engineering (Bilingual) Review Reference: Chapter 8 (Software Testing)
软件工程（双语）复习参考：第 8 章（软件测试）

## Overview
概述

This review covers core knowledge of **Chapter 8 (Software Testing)** and aligns with the second quiz’s key exam points (fill-in-the-blank, true/false, single choice, multiple choice). Core content is presented in English with bilingual annotations for key terms, and directly maps to quiz questions for targeted review.
本次复习涵盖第 8 章（软件测试）的核心知识，并与第二次测验的关键考试要点（填空题、判断题、单选题、多选题）相一致。核心内容以英文呈现，关键术语附有双语注释，并与测验题目直接对应，便于针对性复习。

## Core Knowledge Points (English + Bilingual Key Terms)
核心知识点（英文+双语关键术语）

### 1\. Testing Fundamentals (测试基础)
1\. 测试基础

#### 1.1 Testing Goals & Core Principles
1.1 测试目标与核心原则

*   **Testing Definition**: Intended to show a program meets requirements and discover **defects (缺陷)** before deployment (Quiz Q1).
    测试定义：旨在展示程序满足需求并在部署前发现缺陷（缺陷）（测验 Q1）。
*   **Key Principle**: "Testing can only show the presence of errors, not their absence" (Edsger Dijkstra) – TRUE (Quiz Q2).
    关键原则："测试只能证明错误的存在，不能证明其不存在"（艾德格·迪科斯彻）——正确（测验 Q2）。
*   **V&V (Verification & Validation, 验证与确认)
    V&V（验证与确认）**
    
    | Term术语 | Definition定义 | Chinese Annotation中文注释 | Quiz Q3 Key Trap测验 Q3 关键陷阱 |
    | --- | --- | --- | --- |
    | Verification (验证)验证 | "Are we building the product right?"; Check if software meets stated functional/non-functional requirements."我们的产品做得对吗？"；检查软件是否满足已声明的功能/非功能要求。 | 验证“产品构建是否正确” | Option C (Verification = meet customer expectations) is FALSE (this is Validation).选项 C（验证=满足客户期望）是错误的（这是确认）。 |
    | Validation (确认)确认 | "Are we building the right product?"; Ensure software meets customer expectations."我们是否在构建正确的产品？"；确保软件满足客户期望。 | 确认“是否构建了正确的产品” | \- |
    
*   **V&V Goal**: Establish **confidence (信心)** that software is "fit for purpose" (Quiz Q4).
    V&V 目标：建立信心（信心），确保软件“适合用途”（测验 Q4）。

#### 1.2 Inspections vs Testing (检查 vs 测试)
1.2 检查 vs 测试

| Aspect方面 | Inspections (检查)检查 | Testing (测试)测试 (测试) | Quiz Q5/Q6 Key Points测验 Q5/Q6 要点 |
| --- | --- | --- | --- |
| Type类型 | Static V&V (no software execution)静态 V&V（不执行软件） | Dynamic V&V (requires software execution)动态 V&V（需要软件执行） | Inspections can check requirements/design/code (not only executable programs) – Q5 FALSE.检查可以检查需求/设计/代码（不仅限于可执行程序）——Q5 假。 |
| Incomplete Systems不完整的系统 | No additional cost to inspect检查无需额外成本 | Need specialized test harnesses to test partial programs需要专门的测试框架来测试部分程序 | Q6 Option B is TRUE.Q6 选项 B 为真。 |
| Error Interactions错误交互 | No worry about error interactions (single session finds multiple errors)无需担心错误交互（单次会话可发现多个错误） | Prone to error interactions易出错交互 | Q6 Option C is TRUE.Q6 选项 C 为真。 |
| Strengths优势 | Check broad quality (standards, portability); find more defects than testing检查广泛质量（标准、可移植性）；比测试发现更多缺陷 | Discover interaction/timing/performance defects (inspections do not)发现交互/时间/性能缺陷（检查无法发现） | Q6 Option D is FALSE (Testing is good for these defects; inspections are not).Q6 选项 D 是错误的（测试适用于这些缺陷；检查不适用）。 |

#### 1.3 Testing Process Model (测试过程模型)
1.3 测试过程模型（测试过程模型）

*   **Steps**: Design test cases → Prepare test data → Run program → Compare results with test cases.
    步骤：设计测试用例→准备测试数据→运行程序→将结果与测试用例进行比较。
*   **Automation**: Only **Design test cases (设计测试用例)** cannot be automated (Quiz Q7, Option A).
    自动化：仅设计测试用例（设计测试用例）不能被自动化（测验 Q7，选项 A）。

#### 1.4 Testing Stages (测试阶段)
1.4 测试阶段

*   Three high-level stages: **Development testing (开发测试)**, **Release testing (发布测试)**, User testing (用户测试) (Quiz Q8).
    三个高级阶段：开发测试（开发测试）、发布测试（发布测试）、用户测试（用户测试）（测验 Q8）。

### 2\. Development Testing (开发测试)
2\. 开发测试（开发测试）

#### 2.1 Sub-stages of Development Testing
2.1 开发测试的子阶段

| Sub-stage子阶段 | Focus重点 | Key Term (Quiz Q9/Q10/Q11)关键词（测验题 9/10/11） |
| --- | --- | --- |
| Unit testing (单元测试)单元测试 | Test individual units (methods/object classes); cover (覆盖) all features of objects (attributes, operations, states)测试单个单元（方法/对象类）；覆盖对象的所有功能（属性、操作、状态） | Quiz Q9 (Component), Q10 (coverage), Q11 (interfaces)测验 Q9（组件），Q10（覆盖率），Q11（接口） |
| Component testing (构件测试)构件测试 | Test integrated composite components; focus on interfaces (接口) (access to component functions)测试集成复合组件；关注接口（接口）（访问组件功能） | \- |
| System testing (系统测试)系统测试（系统测试） | Test the integrated system; focus on component interactions测试集成系统；关注组件交互 | \- |

#### 2.2 Unit Testing for Object Classes (对象类的单元测试)
2.2 对象类的单元测试

*   Test all operations/attributes/states of an object; use state models to test state transition sequences (e.g., Shutdown→Configuring→Running→Summarizing):
    测试对象的所有操作/属性/状态；使用状态模型来测试状态转换序列（例如，关机→配置中→运行→总结）：
    *   Reconfigure() (triggers Configuring state), reportWeather() (triggers Summarizing state) are testable (Quiz Q12: Options A, C).
        Reconfigure()（触发配置中状态），reportWeather()（触发总结状态）是可测试的（测验 Q12：选项 A、C）。
    *   Shutdown() (initial state, not triggered in the sequence) and powerSave() (no state transition for this method) are not testable.
        Shutdown()（初始状态，序列中未触发）和 powerSave()（此方法无状态转换）是不可测试的。

#### 2.3 Test Case Design (测试用例设计)

*   **Partition Testing (划分测试)**: Test boundary values + midpoint of equivalence partitions (e.g., interval \[3,9\] → test 2 (lower boundary-), 3 (lower boundary), 6 (midpoint), 9 (upper boundary), 10 (upper boundary+)) (Quiz Q13: Option A is optimal).
    划分测试（划分测试）：测试等价划分的边界值+中点（例如，区间\[3,9\] → 测试 2（下边界-），3（下边界），6（中点），9（上边界），10（上边界+））（测验 Q13：选项 A 是最优的）。
*   **Black-box vs White-box Testing**:
    黑盒测试与白盒测试：
    *   Black-box: No knowledge of system internal working (TRUE).
        黑盒：不了解系统内部工作原理（正确）。
    *   White-box: Look at code to design test cases (TRUE) (Quiz Q14).
        白盒：查看代码来设计测试用例（正确）（测验题 14）。

#### 2.4 Component Testing (构件测试) – Interfaces (接口)
2.4 构件测试（Component Testing）– 接口（Interfaces）

*   **Interface Types**: <u>Parameter interfaces, shared memory interfaces, **procedural (过程) interfaces**, message passing interfaces</u> (Quiz Q15).
    接口类型：参数接口、共享内存接口、过程接口、消息传递接口（测验题 Q15）。
*   **Interface Error Types**: Interface misuse (接口误用), **interface misunderstanding (接口误解)**, timing errors (时序错误) (Quiz Q16).
    接口错误类型：接口误用、接口误解、时序错误（测验题 Q16）。

### 3\. Test-Driven Development (TDD, 测试驱动开发)
3\. 测试驱动开发（TDD）

*   **Core Characteristics**:
    核心特征：
    *   **Interleave** <u>testing and code development</u> (交织测试与代码开发). 
    *   Incremental code development + corresponding tests (增量开发代码+测试). 
    *   **Do NOT start next increment <u>until current code passes all tests</u>** (Quiz Q18: Option C is FALSE). 
    *   Applicable to both agile and plan-driven processes. 
*   **Key Benefit**: <u>Regression testing</u> (回归测试) – run test suite to check for new bugs after code changes (Quiz Q19).
    主要优势：回归测试（回归测试）——在代码变更后运行测试套件以检查新出现的错误（测验题 Q19）。

## Corresponding Quiz Exam Points
相应的测验考试要点

| Quiz Question测验题目 | Type类型 | Core Topic核心主题 | Correct Answer/Key Note正确答案/关键点 |
| --- | --- | --- | --- |
| 1 | Fill-in-the-blank填空题 | Testing goal测试目标 | defects/缺陷 |
| 2 | True/False | Testing principle | TRUE (Testing only shows errors exist, not absence) |
| 3 | Single Choice单选题 | V&V definitionV&V 定义 | C (Verification ≠ meet customer expectations – this is Validation)C（验证≠满足客户期望——这是确认） |
| 4 | Fill-in-the-blank填空题 | V&V goalV&V 目标 | confidence/信心信心 |
| 5 | True/False真/假 | Inspections vs Testing scope检验与测试范围 | FALSE (Inspections can check requirements/design; Testing needs execution)FALSE（检查可以验证需求/设计；测试需要执行） |
| 6 | Single Choice单选题 | Inspections vs Testing characteristics检查与测试的特点 | D (Testing IS good for interaction/timing/performance defects)D（测试非常适合交互/时间/性能缺陷） |
| 7 | Single Choice单选题 | Testing process automation测试过程自动化 | A (Design test cases cannot be automated)A（设计测试用例不能自动化） |
| 8 | Fill-in-the-blank填空题 | Testing stages测试阶段 | release/发布发布 |
| 9 | Fill-in-the-blank填空题 | Development testing sub-stages开发测试子阶段 | Component/构件 |
| 10 | Fill-in-the-blank填空题 | Unit testing for object classes对象类的单元测试 | coverage/覆盖 |
| 11 | Fill-in-the-blank填空题 | Component testing focus组件测试重点 | interfaces/接口接口 |
| 12 | Multiple Choice选择题 | State transition & method testing状态转换与方法测试 | A (reconfigure()), C (reportWeather())A（重新配置()），C（报告天气()） |
| 13 | Single Choice单选 | Partition testing (boundary values)划分测试（边界值） | A (2,3,4,6,8,9,10 – covers boundaries + midpoint)A (2,3,4,6,8,9,10 – 涵盖边界+中点) |
| 14 | True/False判断题 | Black-box vs White-box testing黑盒测试与白盒测试 | TRUE |
| 15 | Fill-in-the-blank填空题 | Interface types接口类型 | Procedural/过程过程式 |
| 16 | Fill-in-the-blank填空式 | Interface error types接口错误类型 | interface misunderstanding/接口误解 |
| 18 | Single Choice单选 | TDD principlesTDD 原则 | C (Cannot start next increment before current tests pass)C（当前测试未通过前不能开始下一个增量） |
| 19 | Fill-in-the-blank填空题 | TDD benefit (regression testing)TDD 的好处（回归测试） | regression/回归回归 |

## Key Review Suggestions
关键审查建议

1.  **V&V Distinction**: Memorize the core difference between Verification ("right product") and Validation ("product right") – this is a frequent single-choice trap.
    V&V 区别：记住验证（产品正确）和确认（正确的产品）之间的核心区别——这是一个常见的单选题陷阱。
2.  **Development Testing Stages**: Master the focus of each sub-stage (Unit = functionality, Component = interfaces, System = interactions) – key fill-in-the-blank points.
    开发测试阶段：掌握每个子阶段的重点（单元=功能，组件=接口，系统=交互）——关键填空点。
3.  **Test Case Design**: Focus on partition testing (boundary + midpoint values) – the most common single-choice question for test case selection.
    测试用例设计：关注划分测试（边界+中间值）——测试用例选择中最常见的单选题。
4.  **Inspections vs Testing**: Remember inspections are static (no execution) and testing is dynamic (execution required); testing is better for interaction/timing/performance defects.
    评审与测试：记住评审是静态的（无需执行）而测试是动态的（需要执行）；测试更适合交互/时间/性能缺陷。
5.  **TDD Core Rules**: Do not start next increment until current code passes all tests; regression testing is a key benefit – critical for true/false/single-choice questions.
    TDD 核心规则：当前代码未通过所有测试前不得开始下一个增量；回归测试是关键收益——对真/假/单选题至关重要。