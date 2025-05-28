-- ⑴ 在预算日期、结算日期和入账日期上分别建立索引
CREATE INDEX idx_预算日期 ON 预算表 (预算日期);
CREATE INDEX idx_结算日期 ON 结算表 (结算日期);
CREATE INDEX idx_入账日期 ON 入账表 (入账日期);
-- ⑵ 删除预算日期、结算日期和入账日期上的索引
DROP INDEX idx_预算日期 ON 预算表;
DROP INDEX idx_结算日期 ON 结算表;
DROP INDEX idx_入账日期 ON 入账表;
-- ⑴ 采油一矿二队2018-5-1到2018-5-28有哪些项目完成了预算，列出相应明细
SELECT 预算表.*,
    单位代码表.单位名称
FROM 预算表
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
WHERE 单位代码表.单位名称 = '采油一矿二队'
    AND 预算表.预算日期 BETWEEN '2018-05-01' AND '2018-05-28';
-- ⑵ 采油一矿二队2018-5-1到2018-5-28有哪些项目完成了结算，列出相应明细
SELECT 结算表.*,
    单位代码表.单位名称
FROM 结算表
    JOIN 预算表 ON 结算表.单据号 = 预算表.单据号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
WHERE 单位代码表.单位名称 = '采油一矿二队'
    AND 结算表.结算日期 BETWEEN '2018-05-01' AND '2018-05-28';
-- ⑶ 采油一矿二队2018-5-1到2018-5-28有哪些项目完成了结算，列出相应的材料费消耗明细
SELECT 材料明细表.*,
    单位代码表.单位名称
FROM 材料明细表
    JOIN 结算表 ON 材料明细表.单据号 = 结算表.单据号
    JOIN 预算表 ON 结算表.单据号 = 预算表.单据号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
WHERE 单位代码表.单位名称 = '采油一矿二队'
    AND 结算表.结算日期 BETWEEN '2018-05-01' AND '2018-05-28';
-- ⑷ 采油一矿二队2018-5-1到2018-5-28有哪些项目完成了入账，列出相应明细
SELECT 入账表.*,
    单位代码表.单位名称
FROM 入账表
    JOIN 结算表 ON 入账表.单据号 = 结算表.单据号
    JOIN 预算表 ON 结算表.单据号 = 预算表.单据号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
WHERE 单位代码表.单位名称 = '采油一矿二队'
    AND 入账表.入账日期 BETWEEN '2018-05-01' AND '2018-05-28';
-- ⑸ 列出采油一矿二队2018-5-1到2018-5-28总的预算金额
SELECT SUM(预算表.预算金额) AS 总预算金额,
    单位代码表.单位名称
FROM 预算表
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
WHERE 单位代码表.单位名称 = '采油一矿二队'
    AND 预算表.预算日期 BETWEEN '2018-05-01' AND '2018-05-28';
-- ⑹ 列出采油一矿二队2018-5-1到2018-5-28总的结算金额
SELECT SUM(结算表.结算金额) AS 总结算金额
FROM 结算表
    JOIN 预算表 ON 结算表.单据号 = 预算表.单据号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
WHERE 单位代码表.单位名称 = '采油一矿二队'
    AND 结算表.结算日期 BETWEEN '2018-05-01' AND '2018-05-28';
-- ⑺ 列出采油一矿二队2018-5-1到2018-5-28总的入账金额
SELECT SUM(入账表.入账金额) AS 总入账金额
FROM 入账表
    JOIN 结算表 ON 入账表.单据号 = 结算表.单据号
    JOIN 预算表 ON 结算表.单据号 = 预算表.单据号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
WHERE 单位代码表.单位名称 = '采油一矿二队'
    AND 入账表.入账日期 BETWEEN '2018-05-01' AND '2018-05-28';
-- ⑻ 列出采油一矿2018-5-1到2018-5-28总的入账金额
SELECT SUM(入账表.入账金额) AS 总入账金额
FROM 入账表
    JOIN 结算表 ON 入账表.单据号 = 结算表.单据号
    JOIN 预算表 ON 结算表.单据号 = 预算表.单据号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
WHERE 单位代码表.单位名称 LIKE '采油一矿%'
    AND 入账表.入账日期 BETWEEN '2018-05-01' AND '2018-05-28';
-- ⑼ 有哪些人员参与了入账操作
SELECT DISTINCT 入账表.入账人
FROM 入账表;
-- ⑽ 列出2018-5-1到2018-5-28进行了结算但未入账的项目
SELECT 结算表.单据号,
    结算表.结算金额,
    结算表.结算日期
FROM 结算表
    LEFT JOIN 入账表 ON 结算表.单据号 = 入账表.单据号
WHERE 入账表.单据号 IS NULL
    AND 结算表.结算日期 BETWEEN '2018-05-01' AND '2018-05-28';
-- ⑾ 列出采油一矿二队的所有项目，按入账金额从高到低排列
SELECT 入账表.单据号,
    入账表.入账金额,
    入账表.入账日期,
    单位名称
FROM 入账表
    JOIN 结算表 ON 入账表.单据号 = 结算表.单据号
    JOIN 预算表 ON 结算表.单据号 = 预算表.单据号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
WHERE 单位代码表.单位名称 = '采油一矿二队'
ORDER BY 入账表.入账金额 DESC;
-- ⑿ 列出有哪些施工单位实施了项目，并计算各单位所有项目结算金额总和
SELECT 结算表.施工单位,
    SUM(结算表.结算金额) AS 总结算金额
FROM 结算表
GROUP BY 结算表.施工单位;
-- ⒀ 找出消耗了材料三且消耗超过了2000元的项目，列出相应消耗明细
SELECT 材料明细表.*
FROM 材料明细表
WHERE 材料明细表.物码 = 'wm003'
    AND 材料明细表.消耗数量 * 材料明细表.单价 > 2000;
-- ⒀ 找出消耗了材料三且消耗超过了2000元的项目，列出相应消耗明细(利用子查询)
SELECT 材料明细表.*
FROM 材料明细表
WHERE 材料明细表.物码 = 'wm003'
    AND 材料明细表.单据号 IN (
        SELECT 单据号
        FROM 材料明细表
        WHERE 材料明细表.消耗数量 * 材料明细表.单价 > 2000
    );
-- ⒁ 作业公司二队参与了哪些项目
SELECT 结算表.单据号,
    结算表.施工内容,
    施工单位
FROM 结算表
WHERE 结算表.施工单位 = '作业公司作业二队';
-- ⒂ 作业公司一队和二队参与了哪些项目（利用union）
SELECT 结算表.单据号,
    结算表.施工内容,
    结算表.结算金额
FROM 结算表
WHERE 结算表.施工单位 = '作业公司作业一队'
UNION
SELECT 结算表.单据号,
    结算表.施工内容,
    结算表.结算金额
FROM 结算表
WHERE 结算表.施工单位 = '作业公司作业二队';
-- ⒃ 采油一矿的油井是哪些作业队参与施工的
SELECT DISTINCT 井别,
    单位名称,
    施工单位
FROM 结算表
    JOIN 预算表 ON 结算表.单据号 = 预算表.单据号
    JOIN 油水井表 ON 预算表.井号 = 油水井表.井号
    JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
WHERE 单位代码表.单位名称 LIKE '采油一矿%'
    AND 油水井表.井别 = '油井';
-- ⑴ 建立数据表(包含3个属性列：★施工单位、★年月、◆结算金额)保存各个施工单位每月的结算金额总和
CREATE TABLE 施工单位月结算表 (
    施工单位 VARCHAR(50) PRIMARY KEY,
    年月 VARCHAR(7) NOT NULL,
    结算金额 MONEY NOT NULL
);
-- 添加施工单位月结算表表注释
EXEC sp_addextendedproperty 
    @name = N'MS_Description', 
    @value = '存储各施工单位每月的结算金额汇总信息', 
    @level0type = N'SCHEMA', @level0name = 'dbo', 
    @level1type = N'TABLE',  @level1name = '施工单位月结算表';

-- 添加施工单位字段注释
EXEC sp_addextendedproperty 
    @name = N'MS_Description', 
    @value = '施工单位名称，外键引用施工单位表', 
    @level0type = N'SCHEMA', @level0name = 'dbo', 
    @level1type = N'TABLE',  @level1name = '施工单位月结算表', 
    @level2type = N'COLUMN', @level2name = '施工单位';

-- 添加年月字段注释
EXEC sp_addextendedproperty 
    @name = N'MS_Description', 
    @value = '结算年月，格式为YYYY-MM', 
    @level0type = N'SCHEMA', @level0name = 'dbo', 
    @level1type = N'TABLE',  @level1name = '施工单位月结算表', 
    @level2type = N'COLUMN', @level2name = '年月';

-- 添加结算金额字段注释
EXEC sp_addextendedproperty 
    @name = N'MS_Description', 
    @value = '对应月份的结算金额', 
    @level0type = N'SCHEMA', @level0name = 'dbo', 
    @level1type = N'TABLE',  @level1name = '施工单位月结算表', 
    @level2type = N'COLUMN', @level2name = '结算金额';
-- ⑵ 用子查询将各个施工单位每月的结算金额总和插入到所建立的数据表中
INSERT INTO 施工单位月结算表 (施工单位, 年月, 结算金额)
SELECT 结算表.施工单位,
    FORMAT(结算表.结算日期, 'yyyy-MM'),
    总结算金额
FROM 结算表
    JOIN (
        SELECT 施工单位,
            FORMAT(结算日期, 'yyyy-MM') AS 年月,
            SUM(结算金额) AS 总结算金额
        FROM 结算表
        GROUP BY 施工单位,
            FORMAT(结算日期, 'yyyy-MM')
    ) AS 子查询 ON 结算表.施工单位 = 子查询.施工单位
    AND FORMAT(结算表.结算日期, 'yyyy-MM') = 子查询.年月
GROUP BY 结算表.施工单位,
    FORMAT(结算表.结算日期, 'yyyy-MM'),
    子查询.总结算金额;
-- ⑵ 将各个施工单位每月的结算金额总和插入到所建立的数据表中
INSERT INTO 施工单位月结算表 (施工单位, 年月, 结算金额)
SELECT 施工单位,
    FORMAT(结算日期, 'yyyy-MM'),
    SUM(结算金额)
FROM 结算表
GROUP BY 施工单位,
    FORMAT(结算日期, 'yyyy-MM');
-- ⑶ 用带子查询的修改语句将采油一矿油井作业项目的结算人改为“李兵”
UPDATE 结算表
SET 结算人 = '李兵'
WHERE 单据号 IN (
        SELECT 预算表.单据号
        FROM 预算表
            JOIN 油水井表 ON 预算表.井号 = 油水井表.井号
            JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
        WHERE 单位代码表.单位名称 LIKE '采油一矿%'
            AND 油水井表.井别 = '油井'
    );
-- ⑷ 用带子查询的删除语句删除采油一矿油井作业项目
BEGIN TRANSACTION;
DELETE FROM 入账表
WHERE 单据号 IN (
        SELECT 预算表.单据号
        FROM 预算表
            JOIN 油水井表 ON 预算表.井号 = 油水井表.井号
            JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
        WHERE 单位代码表.单位名称 LIKE '采油一矿%'
            AND 油水井表.井别 = '油井'
    );
-- 其次，删除材料明细表中与采油一矿油井作业项目相关的记录
DELETE FROM 材料明细表
WHERE 单据号 IN (
        SELECT 预算表.单据号
        FROM 预算表
            JOIN 油水井表 ON 预算表.井号 = 油水井表.井号
            JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
        WHERE 单位代码表.单位名称 LIKE '采油一矿%'
            AND 油水井表.井别 = '油井'
    );
-- 然后，删除结算表中与采油一矿油井作业项目相关的记录
DELETE FROM 结算表
WHERE 单据号 IN (
        SELECT 预算表.单据号
        FROM 预算表
            JOIN 油水井表 ON 预算表.井号 = 油水井表.井号
            JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
        WHERE 单位代码表.单位名称 LIKE '采油一矿%'
            AND 油水井表.井别 = '油井'
    );
-- 最后，删除预算表中与采油一矿油井作业项目相关的记录
DELETE FROM 预算表
WHERE 单据号 IN (
        SELECT 预算表.单据号
        FROM 预算表
            JOIN 油水井表 ON 预算表.井号 = 油水井表.井号
            JOIN 单位代码表 ON 预算表.预算单位 = 单位代码表.单位代码
        WHERE 单位代码表.单位名称 LIKE '采油一矿%'
            AND 油水井表.井别 = '油井'
    );
-- ⑸ 撤消上述两个操作
ROLLBACK TRANSACTION;
