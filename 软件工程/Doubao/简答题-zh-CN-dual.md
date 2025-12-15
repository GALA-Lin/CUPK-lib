以下是这4道简答题的标准答题模板（符合考试要求，基于PPT内容+课程核心知识点）：

### 1\. Explain the concept and benefits of software prototyping.

![img](E:\CUPK-lib\软件工程\Doubao\简答题-zh-CN-dual.assets\clip_image002-1764297268335-13.gif)

![img](E:\CUPK-lib\软件工程\Doubao\简答题-zh-CN-dual.assets\clip_image004-1764297268336-14.gif)



1\. 解释软件原型设计的概念和优势。

*   **Concept of software prototyping**: A software prototype is an initial version of a system. Its core purpose is to demonstrate concepts of the system and try out different design options (e.g., interface layouts, function logic) during the early development stage.
    软件原型设计的概念：软件原型是一个系统的初始版本。其核心目的是在早期开发阶段展示系统的概念，并尝试不同的设计选项（例如，界面布局、功能逻辑）。
    
*   **Benefits of prototyping**:
    原型设计的优势：
    1.  Help potential users evaluate how well the system supports their work (verify system applicability).
        帮助潜在用户评估系统如何支持他们的工作（验证系统的适用性）。
    2.  Enable users to find strengths/weaknesses of initial requirements and propose new system requirements.
        使用户能够发现初始需求的优势/劣势，并提出新的系统需求。
    3.  Reveal errors (e.g., logical conflicts) and omissions in the system requirements during prototype development.
        在原型开发过程中揭示系统需求中的错误（例如，逻辑冲突）和遗漏。
    4.  Allow design experiments to check the feasibility of a proposed design (e.g., technical implementation of a key function).
        允许设计实验来验证所提出设计的可行性（例如，关键功能的技术实现）。

### 2\. Explain the content of Agile manifesto.

![image-20251128103107224](E:\CUPK-lib\软件工程\Doubao\简答题-zh-CN-dual.assets\image-20251128103107224.png)

2\. 解释敏捷宣言的内容。

The Agile Manifesto was issued by leading agile method developers, and it defines 4 core values (prioritizing the left items over the right ones, while acknowledging the value of the right items):
敏捷宣言是由主要的敏捷方法开发者发布的，它定义了 4 个核心价值观（优先考虑左侧项目，同时承认右侧项目的价值）：

1.  **Individuals and interactions** over processes and tools;
    个人和互动胜过流程和工具；
2.  **Working software** over comprehensive documentation;
    运行中的软件胜过详尽的文档；
3.  **Customer collaboration** over contract negotiation;
    客户合作胜过合同协商；
4.  **Responding to change** over following a plan.
    应对变化胜过遵循计划。

The manifesto emphasizes that agile development focuses on flexible, people-centric collaboration and delivering usable software, rather than rigid processes or excessive documentation.
该宣言强调敏捷开发注重灵活、以人为本的协作和交付可用软件，而不是僵化的流程或过多的文档。

### 3\. Explain the concepts of verification and validation and their difference.

![image-20251128103113323](E:\CUPK-lib\软件工程\Doubao\简答题-zh-CN-dual.assets\image-20251128103113323.png)

3\. 解释验证和确认的概念及其区别。

*   **Verification**: The core question of verification is *“Are we building the product right?”*. It is the process of checking whether the software meets its **stated functional and non-functional requirements** (e.g., verifying if a payment function complies with the specified response time).
    验证：验证的核心问题是“我们是否在正确地构建产品？”。它是检查软件是否满足其声明的功能和非功能要求的过程（例如，验证支付功能是否符合指定的响应时间）。
    
*   **Validation**: The core question of validation is *“Are we building the right product?”*. Its aim is to ensure the software meets **customer’s expectations** (e.g., confirming if the payment function is easy enough for target users to operate).
    确认：验证的核心问题是“我们是否在构建正确的产品？”。其目的是确保软件满足客户期望（例如，确认支付功能是否足够简单，以便目标用户能够操作）。
    
*   **Key difference**: Verification focuses on *compliance with predefined specifications*; validation focuses on *alignment with actual user needs* (requirements may not fully reflect user expectations).
    关键区别：验证关注的是是否符合预定义的规范；而确认关注的是是否与实际用户需求一致（需求可能无法完全反映用户期望）。
    

### 4\. Explain the four essential elements of design patterns defined by “The Gang of Four”.

![image-20251128103120376](E:\CUPK-lib\软件工程\Doubao\简答题-zh-CN-dual.assets\image-20251128103120376.png)

4\. 解释“四人帮”定义的设计模式的四个基本要素。

The Gang of Four (GoF) defined 4 essential elements for a design pattern:
“四人帮”（GoF）为设计模式定义了四个基本要素：

1.  **Name**: A meaningful label for the pattern (e.g., “Singleton”), which helps communicate the pattern concisely.
    名称：为模式提供一个有意义的标签（例如，“单例”），以帮助简洁地传达模式。
2.  **Problem description**: An explanation of the scenarios (contexts) where the pattern is applicable (e.g., when only one instance of a class should exist).
    问题描述：对模式适用的场景（上下文）的解释（例如，当类应该只存在一个实例时）。
3.  **Solution description**: A specification of the design’s components, their relationships, and their responsibilities. It provides a general template that can be instantiated in different ways.
    解决方案描述：设计组件的规范、它们之间的关系及其职责。它提供了一个通用的模板，可以以不同的方式实例化。
4.  **Consequences (trade-offs)**: A statement of the results (benefits) and trade-offs (drawbacks) of applying the pattern. This helps designers decide whether to use the pattern in a specific situation.
    后果（权衡）：应用模式的结果（收益）和权衡（缺点）的陈述。这有助于设计者在特定情况下决定是否使用该模式。