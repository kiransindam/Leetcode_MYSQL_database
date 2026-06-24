WITH FriendCounts AS (
    SELECT id, COUNT(*) AS num
    FROM (
        SELECT requester_id AS id FROM RequestAccepted
        UNION ALL
        SELECT accepter_id AS id FROM RequestAccepted
    ) AS all_ids
    GROUP BY id
),
Ranked AS (
    SELECT id, num, RANK() OVER (ORDER BY num DESC) AS rnk
    FROM FriendCounts
)
SELECT id, num
FROM Ranked
WHERE rnk = 1;