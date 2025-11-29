基于Mentcare心理健康护理系统的核心业务场景（患者信息管理、离线访问、数据保密、多场景部署），结合软件 engineering 1-8章核心知识点，设计以下综合题及标准答题模板（适配期末 exam 要求，覆盖需求、架构、建模、测试四大模块）：

* * *

### Comprehensive Case Study: Mentcare System
综合案例研究：Mentcare 系统

#### Background
背景

Mentcare is a medical information system designed for mental health clinics, community centers, and home visits. It maintains detailed patient records (mental health conditions, treatments, consultations) and supports both centralized database access (via hospital servers) and offline use on laptops (for remote clinics without network connectivity). Key requirements include strict patient data confidentiality, compliance with mental health laws, and seamless synchronization between local and central data sources. Stakeholders include clinicians, nurses, system administrators, and government mental health act administrators.
Mentcare 是一个专为心理健康诊所、社区中心和居家访视设计的医疗信息系统。它维护详细的病人记录（心理健康状况、治疗记录、咨询记录），并支持通过医院服务器进行集中数据库访问以及在没有网络连接的远程诊所中通过笔记本电脑进行离线使用。主要需求包括严格的患者数据保密性、符合心理健康法规以及本地和中央数据源之间的无缝同步。利益相关方包括临床医生、护士、系统管理员和政府心理健康法规管理员。

#### Tasks (Answer All Parts)
任务（回答所有部分）

1.  **Requirements Analysis
    需求分析**
    Identify 3 core functional requirements (FRs) and 3 critical non-functional requirements (NFRs) of the Mentcare system, and explain why each NFR is essential for mental health services.
    识别 Mentcare 系统的 3 个核心功能需求（FRs）和 3 个关键非功能需求（NFRs），并解释每个 NFR 对心理健康服务的重要性。
2.  **Architectural Design
    架构设计**
    Propose a suitable architectural pattern for Mentcare and draw a high-level architecture diagram (text description acceptable). Justify your choice based on the system’s characteristics.
    为 Mentcare 提出一个合适的架构模式，并绘制高层架构图（文字描述可接受）。根据系统的特性说明选择理由。
3.  **System Modeling
    系统建模**
    a) Draw a use case diagram for the "nurse home visit" scenario (include key actors and use cases).
    a) 为"护士家访"场景绘制用例图（包括关键参与者和使用案例）。
    b) Describe the sequence of interactions for the scenario: "A nurse downloads a patient’s record to a laptop, updates treatment notes offline, and synchronizes data back to the central server."
    b) 描述该场景中的交互顺序："一名护士将患者的记录下载到笔记本电脑上，离线更新治疗记录，并将数据同步回中央服务器。"
4.  **Testing Strategy
    测试策略**
    Design 2 release test scenarios for Mentcare, covering both functional and non-functional requirements. For each scenario, specify preconditions, test steps, and expected results.
    为 Mentcare 设计 2 个发布测试场景，涵盖功能性和非功能性需求。对于每个场景，指定前提条件、测试步骤和预期结果。

* * *

### Standard Answer Template
标准答案模板

#### 1\. Requirements Analysis
1\. 需求分析

*   **Functional Requirements (FRs)**:
    功能性需求（FRs）：
    
    1.  Allow authorized clinicians to create, edit, and query patient mental health records (including diagnoses, medications, and consultation notes) .
        允许授权的临床医生创建、编辑和查询患者心理健康记录（包括诊断、药物和咨询记录）。
    2.  Support offline download/synchronization of patient records to laptops, with encryption for local data storage .
        支持将患者记录离线下载/同步到笔记本电脑，并对本地存储数据进行加密。
    3.  Generate standardized reports (e.g., treatment progress, mental health act compliance) for government administrators .
        为政府管理员生成标准化报告（例如，治疗进展、心理健康行为合规性）。
*   **Non-Functional Requirements (NFRs)**:
    非功能性需求（NFRs）：
    
    1.  **Confidentiality**: Patient data must only be accessible to authorized staff; hospital managers shall not access individual records .
        保密性：患者数据只能供授权人员访问；医院管理人员不得访问个人记录。
        *   Rationale: Mental health records are highly sensitive; unauthorized access violates privacy laws and erodes patient trust.
            理由：心理健康记录高度敏感；未经授权的访问违反隐私法并损害患者信任。
    2.  **Reliability**: Offline data must not be corrupted during synchronization; the system shall operate without failure for 99.9% of clinical hours .
        可靠性：离线数据在同步过程中不得损坏；系统应在临床时间的 99.9%内无故障运行。
        *   Rationale: System failure could lead to incorrect treatment decisions, compromising patient safety (Mentcare is a safety-critical system) .
            理由：系统故障可能导致错误的治疗决策，危及患者安全（Mentcare 是一个安全关键系统）。
    3.  **Compatibility**: Must run on Linux servers (32GB maximum memory) and laptop devices with limited storage .
        兼容性：必须在 Linux 服务器（最大内存 32GB）和存储空间有限的笔记本电脑设备上运行。
        *   Rationale: The system is deployed across diverse clinical environments (hospitals, community centers) with fixed hardware resources.
            理由：该系统部署在多种临床环境（医院、社区中心）中，硬件资源固定。

#### 2\. Architectural Design
2\. 架构设计

*   **Proposed Pattern**: Layered Architecture + Client-Server Pattern (hybrid design)
    建议模式：分层架构+客户端-服务器模式（混合设计）
*   **High-Level Architecture (Text Description)**:
    高层架构（文本描述）：
    
    ```
    Client Layer (Laptop/Desktop)          Server Layer (Central Linux Server)
    ┌───────────────────────────┐         ┌───────────────────────────────────┐
    │  Presentation Layer        │         │  Presentation Layer (Web Portal)  │
    │  (UI for clinicians/nurses)│◄───────►│  (Reports, admin functions)       │
    ├───────────────────────────┤         ├───────────────────────────────────┤
    │  Application Layer         │         │  Application Layer                │
    │  (Offline data management, │         │  (Data validation, access control,│
    │   encryption, sync logic)  │         │   report generation)              │
    ├───────────────────────────┤         ├───────────────────────────────────┤
    │  Data Access Layer         │         │  Data Access Layer                │
    │  (Local database interface)│         │  (Central database interface)     │
    └───────────────────────────┘         └───────────────────────────────────┘
                                            │
                                            ▼
                                        Data Layer
                                        (Central patient database)
    ```
    
*   **Justification**:
    理由：
    1.  **Layered Architecture**: Separates concerns (presentation → application → data) to simplify maintenance and compliance updates (e.g., changing privacy rules only affects the application layer) .
        分层架构：分离关注点（表现层→应用层→数据层），以简化维护和合规性更新（例如，更改隐私规则仅影响应用层）。
    2.  **Client-Server Pattern**: Enables centralized data management (ensures data consistency) and offline client access (critical for remote clinics) .
        客户端-服务器模式：实现集中数据管理（确保数据一致性）和离线客户端访问（对远程诊所至关重要）。
    3.  **Hybrid Advantage**: Addresses Mentcare’s dual needs (secure central storage + flexible offline use) better than a single pattern (e.g., pure MVC is unsuitable for distributed synchronization).
        混合优势：比单一模式（例如，纯 MVC 不适合分布式同步）更好地解决了 Mentcare 的双重需求（安全的中央存储+灵活的离线使用）。

#### 3\. System Modeling
3\. 系统建模

##### a) Use Case Diagram for "Nurse Home Visit"
a) "护士家庭访问"用例图

*   **Actors**: Nurse, Mentcare System, Central Database
    参与者：护士，Mentcare 系统，中央数据库
    
*   **Use Cases**:
    用例：
    
    1.  Log in to the system (authentication)
        登录系统（身份验证）
    2.  Download patient records to laptop (with encryption)
        将患者记录下载到笔记本电脑（带加密）
    3.  View patient summary information
        查看患者摘要信息
    4.  Update treatment notes/offline changes
        更新治疗记录/离线更改
    5.  Synchronize updated records to central database
        将更新后的记录同步到中央数据库
    6.  Generate follow-up appointment alerts
        生成后续预约提醒
*   **Textual Representation**:
    文本表示：
    `Nurse → [Log in] → Mentcare System; Nurse → [Download patient records] → Mentcare System; Mentcare System → [Encrypt local data] → Laptop; Nurse → [Update notes] → Mentcare System; Mentcare System → [Synchronize] → Central Database`
    

##### b) Sequence Diagram for Offline Data Synchronization
b) 离线数据同步的时序图

1.  Nurse logs into Mentcare client on laptop (enters credentials for authentication).
    护士在笔记本电脑上登录 Mentcare 客户端（输入凭证进行身份验证）。
2.  Client sends authentication request to central server; server validates and returns access token.
    客户端向中央服务器发送身份验证请求；服务器验证并返回访问令牌。
3.  Nurse selects target patient records and requests offline download.
    护士选择目标患者记录并请求离线下载。
4.  Client fetches encrypted patient data from central database via the server.
    客户端通过服务器从中央数据库获取加密的患者数据。
5.  Client decrypts data with the nurse’s key phrase, stores it locally, and re-encrypts for local security.
    客户端使用护士的密钥短语解密数据，将其本地存储，并重新加密以保障本地安全。
6.  Nurse updates treatment notes (e.g., medication side effects) while offline.
    护士在离线状态下更新治疗记录（例如，药物副作用）。
7.  When back online, client sends a synchronization request (with updated data) to the server.
    当重新上线时，客户端向服务器发送同步请求（包含更新后的数据）。
8.  Server validates data integrity, checks for conflicts (e.g., concurrent edits), and merges changes into the central database.
    服务器验证数据完整性，检查冲突（例如并发编辑），并将更改合并到中央数据库。
9.  Server confirms successful synchronization to the client; client updates local records to match the server.
    服务器确认成功同步到客户端；客户端更新本地记录以匹配服务器。

#### 4\. Testing Strategy
4\. 测试策略

##### Test Scenario 1: Offline Data Synchronization (Functional Requirement)
测试场景 1：离线数据同步（功能需求）

*   **Preconditions**:
    前提条件：
    *   Nurse has valid credentials; central database contains patient "Jim’s" record (medication: antidepressants).
        护士拥有有效凭证；中央数据库包含患者“吉姆”的记录（药物：抗抑郁药）。
    *   Laptop is connected to the network initially, then disconnected during note editing.
        笔记本电脑最初连接到网络，然后在编辑记录时断开连接。
*   **Test Steps**:
    测试步骤：
    1.  Nurse logs into Mentcare client on laptop and downloads Jim’s record.
        护士在笔记本电脑上登录 Mentcare 客户端并下载吉姆的记录。
    2.  Disable laptop network connection (simulate offline mode).
        禁用笔记本电脑的网络连接（模拟离线模式）。
    3.  Nurse edits Jim’s record: adds "sleeplessness as medication side effect" and requests a follow-up appointment.
        护士编辑吉姆的记录：添加"失眠作为药物副作用"并请求复诊。
    4.  Re-enable network connection and trigger synchronization.
        重新启用网络连接并触发同步。
    5.  Check the central database for updated records.
        检查中央数据库以获取更新记录。
*   **Expected Results**:
    预期结果：
    *   Jim’s record in the central database includes the new side effect note and appointment request.
        中央数据库中的吉姆记录包括新的副作用备注和预约请求。
    *   No data loss or corruption occurs during synchronization.
        同步过程中没有数据丢失或损坏。

##### Test Scenario 2: Unauthorized Access Prevention (Non-Functional Requirement: Confidentiality)
测试场景 2：未授权访问预防（非功能性需求：保密性）

*   **Preconditions**:
    前置条件：
    *   Hospital manager (unauthorized for patient data) has a system account with administrative privileges.
        医院经理（无权访问患者数据）有一个具有管理员权限的系统账户。
    *   Central database contains 10+ patient mental health records.
        中央数据库包含 10 条以上的患者心理健康记录。
*   **Test Steps**:
    测试步骤：
    1.  Hospital manager logs into the Mentcare web portal.
        医院经理登录 Mentcare 网页门户。
    2.  Attempt to access a patient’s detailed mental health record (e.g., diagnosis, treatment plan).
        尝试访问患者的详细心理健康记录（例如，诊断、治疗计划）。
    3.  Attempt to download patient records to a local device.
        尝试将患者记录下载到本地设备。
*   **Expected Results**:
    预期结果：
    *   The system blocks access to detailed patient records (displays "Insufficient privileges" message).
        系统阻止访问详细的病人记录（显示"权限不足"消息）。
    *   Download functionality is disabled for the manager’s account.
        管理员的账户下载功能被禁用。
    *   Access attempt is logged in the system’s security audit trail.
        访问尝试被记录在系统的安全审计日志中。

* * *

### Key Knowledge Mapping
关键知识图谱

| Task任务 | Related Chapters相关章节 | Core Knowledge Points核心知识点 |
| --- | --- | --- |
| Requirements Analysis需求分析 | Chapter 4第四章 | Functional vs. Non-Functional Requirements; Stakeholder Needs功能需求与非功能需求；干系人需求 |
| Architectural Design架构设计 | Chapter 6第六章 | Architectural Patterns (Layered/Client-Server); Design Justification based on NFRs架构模式（分层/客户端-服务器）；基于 NFRs 的设计理由 |
| System Modeling系统建模 | Chapter 5第五章 | Use Case Diagrams; Sequence Diagrams; System Interaction Logic用例图；时序图；系统交互逻辑 |
| Testing Strategy测试策略 | Chapter 8第 8 章 | Release Testing; Scenario Testing; Functional/Non-Functional Test Design发布测试；场景测试；功能/非功能测试设计 |

This case study integrates core concepts from the entire course and aligns with the Mentcare system’s real-world characteristics (offline use, data security, multi-stakeholder needs). For exam preparation, focus on justifying design choices with system-specific requirements and ensuring test scenarios are realistic and measurable.
这个案例研究整合了整个课程的核心概念，并与 Mentcare 系统的实际特点（离线使用、数据安全、多方利益相关者的需求）相一致。在备考时，应专注于用系统特定的要求来论证设计选择，并确保测试场景是真实且可衡量的。