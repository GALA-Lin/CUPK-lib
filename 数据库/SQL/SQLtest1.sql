-- 创建单位代码表
CREATE TABLE 单位代码表 (
    单位代码 VARCHAR(10) PRIMARY KEY,
    单位名称 VARCHAR(50) NOT NULL UNIQUE,
);

-- 创建油水井表
CREATE TABLE 油水井表 (
    井号 VARCHAR(10) PRIMARY KEY,
    井别 VARCHAR(10) NOT NULL CHECK (井别 IN ('油井', '水井')),
    单位代码 VARCHAR(10) NOT NULL,
    FOREIGN KEY (单位代码) REFERENCES 单位代码表(单位代码)
);

-- 创建施工单位表
CREATE TABLE 施工单位表 (
    施工单位名称 VARCHAR(50) PRIMARY KEY
);

-- 创建物码表
CREATE TABLE 物码表 (
    物码 VARCHAR(10) PRIMARY KEY,
    名称规格 VARCHAR(50) NOT NULL UNIQUE,
    计量单位 VARCHAR(10) NOT NULL,
    单价 MONEY NOT NULL DEFAULT 10
);

-- 创建预算表
CREATE TABLE 预算表 (
    单据号 VARCHAR(20) PRIMARY KEY,
    预算单位 VARCHAR(10) NOT NULL,
    井号 VARCHAR(10) NOT NULL,
    预算金额 MONEY NOT NULL,
    预算人 VARCHAR(20) NOT NULL,
    预算日期 DATE NOT NULL,
    FOREIGN KEY (预算单位) REFERENCES 单位代码表(单位代码),
    FOREIGN KEY (井号) REFERENCES 油水井表(井号)
);

-- 创建结算表
CREATE TABLE 结算表 (
    单据号 VARCHAR(20) PRIMARY KEY,
    开工日期 DATE NOT NULL,
    完工日期 DATE NOT NULL,
    施工单位 VARCHAR(50) NOT NULL,
    施工内容 VARCHAR(100) NOT NULL,
    材料费 MONEY NOT NULL,
    人工费 MONEY NOT NULL,
    设备费 MONEY NOT NULL,
    其它费用 MONEY NOT NULL,
    结算金额 MONEY NOT NULL,
    结算人 VARCHAR(20) NOT NULL,
    结算日期 DATE NOT NULL,
    FOREIGN KEY (单据号) REFERENCES 预算表(单据号),
    FOREIGN KEY (施工单位) REFERENCES 施工单位表(施工单位名称)
);

-- 创建材料明细表
CREATE TABLE 材料明细表 (
    单据号 VARCHAR(20) NOT NULL,
    物码 VARCHAR(10) NOT NULL,
    消耗数量 FLOAT NOT NULL,
    单价 MONEY NOT NULL,
    PRIMARY KEY (单据号, 物码),
    FOREIGN KEY (单据号) REFERENCES 结算表(单据号),
    FOREIGN KEY (物码) REFERENCES 物码表(物码)
);

-- 创建入账表
CREATE TABLE 入账表 (
    单据号 VARCHAR(20) PRIMARY KEY,
    入账金额 MONEY NOT NULL,
    入账人 VARCHAR(20) NOT NULL,
    入账日期 DATE NOT NULL,
    FOREIGN KEY (单据号) REFERENCES 结算表(单据号)
);