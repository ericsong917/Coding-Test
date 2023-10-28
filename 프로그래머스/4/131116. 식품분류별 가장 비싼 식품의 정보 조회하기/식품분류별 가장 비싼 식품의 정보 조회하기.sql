-- 코드를 입력하세요
SELECT T1.CATEGORY, T1.MAX_PRICE AS MAX_PRICE, T2.PRODUCT_NAME
FROM 
(SELECT CATEGORY, MAX(PRICE) AS MAX_PRICE 
FROM FOOD_PRODUCT F
WHERE (CATEGORY = '과자' OR CATEGORY = '국' OR CATEGORY = '김치' OR CATEGORY='식용유') 
GROUP BY CATEGORY) T1, 
FOOD_PRODUCT T2
WHERE T1.CATEGORY=T2.CATEGORY AND T1.MAX_PRICE = T2.PRICE
ORDER BY MAX_PRICE DESC;
