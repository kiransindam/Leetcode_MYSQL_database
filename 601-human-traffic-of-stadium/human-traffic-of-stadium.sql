WITH Filtered AS (
    SELECT *,
           ROW_NUMBER() OVER (ORDER BY id) AS rn
    FROM Stadium
    WHERE people >= 100
),
Grouped AS (
    SELECT *,
           id - rn AS grp
    FROM Filtered
),
ValidGroups AS (
    SELECT grp
    FROM Grouped
    GROUP BY grp
    HAVING COUNT(*) >= 3
)
SELECT s.id, s.visit_date, s.people
FROM Stadium s
JOIN Grouped g ON s.id = g.id
JOIN ValidGroups v ON g.grp = v.grp
ORDER BY s.visit_date;