DEVELOPERS 테이블에서 Python이나 C# 스킬을 가진 개발자의 정보를 조회
조건에 맞는 개발자의 ID, 이메일, 이름, 성을 조회하는 SQL 문을 작성
결과는 ID를 기준으로 오름차순 정렬

-- 1트(성공), 비트연산 사용
SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS
WHERE SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'Python')
    OR SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'C#')
ORDER BY ID ASC