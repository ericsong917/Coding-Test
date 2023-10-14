-- 코드를 입력하세요
SELECT P.PRODUCT_ID, P.PRODUCT_NAME, SUM(PRICE * AMOUNT) AS TOTAL_SALES
FROM FOOD_ORDER O, FOOD_PRODUCT P
WHERE O.PRODUCT_ID = P.PRODUCT_ID
AND MONTH(PRODUCE_DATE)='05'
AND YEAR(PRODUCE_DATE) = '2022'
GROUP BY PRODUCT_ID
ORDER BY TOTAL_SALES DESC, P.PRODUCT_ID ASC
