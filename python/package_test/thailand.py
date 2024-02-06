class ThailandPackage:
    def detail(self):
        print("[태국 패키지] 방콕, 파타야 여행")

if __name__ == "__main__":
    print("Thailand 모듈을 직접 실행한 경우만 실행됨")
    trip_to = ThailandPackage()
    trip_to.detail()
else:
    print("Thailand 외부에서 모듈 호출")