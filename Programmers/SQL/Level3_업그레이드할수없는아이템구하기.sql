더 이상 업그레이드할 수 없는 아이템의 아이템 ID(ITEM_ID), 아이템 명(ITEM_NAME), 
아이템의 희귀도(RARITY)를 출력하는 SQL 문을 작성
이때 결과는 아이템 ID를 기준으로 내림차순 정렬

-- 1트(성공), 생각을 좀 했던 문제?
-- 결국 더 이상 업그레이드가 안되는 것은 PARENT_ITEM_ID로 ITEM_ID가 없어야하는 것
SELECT ITEM_ID, ITEM_NAME, RARITY
FROM ITEM_INFO
WHERE ITEM_ID NOT IN (SELECT PARENT_ITEM_ID FROM ITEM_TREE WHERE PARENT_ITEM_ID IS NOT NULL)
ORDER BY ITEM_ID DESC
