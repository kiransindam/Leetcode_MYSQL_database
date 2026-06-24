WITH Counts AS (
    SELECT 
        tiv_2016,
        COUNT(*) OVER (PARTITION BY tiv_2015) AS cnt_2015,
        COUNT(*) OVER (PARTITION BY lat, lon) AS cnt_loc
    FROM Insurance
)
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Counts
WHERE cnt_2015 > 1 AND cnt_loc = 1;