USED_GOODS_BOARD와 USED_GOODS_USER 테이블

중고 거래 게시물을 3건 이상 등록한 사용자의 사용자 ID, 닉네임, 전체주소, 전화번호를 조회하는 SQL문
전체 주소는 시, 도로명 주소, 상세 주소가 함께 출력
전화번호의 경우 xxx-xxxx-xxxx 같은 형태로 하이픈 문자열(-)을 삽입하여 출력
결과는 회원 ID를 기준으로 내림차순 정렬

-- 1트(성공)
SELECT USERINFO.USER_ID, USERINFO.NICKNAME, CONCAT(CITY, ' ', STREET_ADDRESS1, ' ', STREET_ADDRESS2) AS '전체주소',
    REGEXP_REPLACE(USERINFO.TLNO, '(02|.{3})(.+)(.{4})', '$1-$2-$3') AS '전화번호'
FROM USED_GOODS_USER AS USERINFO
JOIN USED_GOODS_BOARD AS GOODSBOARD ON GOODSBOARD.WRITER_ID = USERINFO.USER_ID
GROUP BY USERINFO.USER_ID
HAVING COUNT(USERINFO.USER_ID) >= 3
ORDER BY USERINFO.USER_ID DESC

-- * 성공했으나 찾아보았던 항목
-- 전화번호에 하이픈 문자열을 삽입하여 출력하기 위한 방법
-- REGEXP_REPLACE() 함수를 사용하여 전화번호 정규식을 통해 하이픈을 추가해줌

-- * 다른 사람의 풀이의 경우 문자열을 잘라서 CONCAT으로 다시 붙임
-- CONCAT(SUBSTR(TLNO,1,3), '-', SUBSTR(TLNO,4,4), '-', SUBSTR(TLNO,8,4))