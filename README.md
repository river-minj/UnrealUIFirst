UnrealUIFirst

개요

Unreal Engine 5 아웃게임 UI 학습 프로젝트입니다. UMG(Unreal Motion Graphics)와 C++를 사용하여 타이틀 화면, 로비, 상점, 인벤토리, 설정 등 아웃게임 UI의 핵심 구조를 구현합니다.


개발 환경
- Unreal Engine 5.5.4
- IDE Visual Studio 2022 Community
- 언어 C++ / Blueprint


구현 기능
1. 화면 전환
 - 타이틀 화면 → 로비 화면 양방향 전환
 - CreateWidget / AddToViewport / RemoveFromParent 기반 화면 관리
 - 페이드인/페이드아웃 애니메이션 (UMG Animation, BindWidgetAnim)
2. 로비
 - Widget Switcher 기반 탭 전환 (상점 / 인벤토리 / 설정)
 - 뒤로가기 버튼으로 타이틀 복귀
3. 상점
 - ListView로 아이템 목록 표시
 - IUserObjectListEntry 인터페이스 기반 Entry Widget
 - 임시데이터: 장검(1000G), 단검(500G), 방패(800G), 물약(100G)
4. 인벤토리
 - TileView로 아이템 격자 표시
 - 임시데이터: 장검(x1), 단검(x3), 방패(x1), 물약(x10)
5. 설정
 - BGM / SFX 볼륨 슬라이더 (USlider, 0~100 값 표시)
 - 전체화면 토글 (UCheckBox)
 - 언어 선택 드롭다운 (UComboBoxString, 한국어/English)


프로젝트 구조
```
First/
├── Content/
│   ├── BP_TitleGameMode.uasset
│   ├── WBP_TitleScreen.uasset
│   ├── WBP_Lobby.uasset
│   ├── WBP_ShopItemEntry.uasset
│   ├── WBP_InventoryItemEntry.uasset
│   └── WBP_Settings.uasset
└── Source/First/
    ├── TitleScreenWidget.h / .cpp
    ├── LobbyWidget.h / .cpp
    ├── SettingsWidget.h / .cpp
    ├── ShopItemData.h / .cpp
    ├── ShopItemEntry.h / .cpp
    ├── InventoryItemData.h / .cpp
    └── InventoryItemEntry.h / .cpp
```


설계 패턴

C++ + Blueprint 위젯 세트
각 화면은 C++ 클래스(헤더 + 소스)와 Widget Blueprint로 구성됩니다.
BindWidget으로 C++ 변수와 블루프린트 위젯을 바인딩하고, 로직은 C++에서, 시각적 배치는 블루프린트 디자이너에서 처리합니다.


Git LFS
.uasset과 .umap 파일은 Git LFS로 관리됩니다. 클론 전에 Git LFS가 설치되어 있어야 합니다.
