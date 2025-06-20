-- ⑷ 用带子查询的删除语句删除采油一矿油井作业项目

-- 首先，删除入账表中与采油一矿油井作业项目相关的记录
DELETE FROM 入账表
WHERE 单据号 IN (
    SELECT 预算表.单据号
    FROM 预算表
    JOIN 油水井表 ON 预算表.井号 = 油水井表.井号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
    WHERE 单位代码表.单位名称 LIKE '采油一矿%' AND 油水井表.井别 = '油井'
);

-- 其次，删除材料明细表中与采油一矿油井作业项目相关的记录
DELETE FROM 材料明细表
WHERE 单据号 IN (
    SELECT 预算表.单据号
    FROM 预算表
    JOIN 油水井表 ON 预算表.井号 = 油水井表.井号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
    WHERE 单位代码表.单位名称 LIKE '采油一矿%' AND 油水井表.井别 = '油井'
);

-- 然后，删除结算表中与采油一矿油井作业项目相关的记录
DELETE FROM 结算表
WHERE 单据号 IN (
    SELECT 预算表.单据号
    FROM 预算表
    JOIN 油水井表 ON 预算表.井号 = 油水井表.井号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
    WHERE 单位代码表.单位名称 LIKE '采油一矿%' AND 油水井表.井别 = '油井'
);

-- 最后，删除预算表中与采油一矿油井作业项目相关的记录
DELETE FROM 预算表
WHERE 单据号 IN (
    SELECT 预算表.单据号
    FROM 预算表
    JOIN 油水井表 ON 预算表.井号 = 油水井表.井号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
    WHERE 单位代码表.单位名称 LIKE '采油一矿%' AND 油水井表.井别 = '油井'
);