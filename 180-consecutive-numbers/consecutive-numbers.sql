# Write your MySQL query statement below
WITH OrderedLogs AS (
    SELECT 
        num,
        LEAD(num, 1) OVER (ORDER BY id) AS next_num1,
        LEAD(num, 2) OVER (ORDER BY id) AS next_num2
    FROM Logs
)
SELECT DISTINCT num AS ConsecutiveNums
FROM OrderedLogs
WHERE num = next_num1 AND num = next_num2;