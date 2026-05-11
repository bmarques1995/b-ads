#pragma once

#include <QFlags>
class QWidget;
class QSplitter;

// DLL Export API
#ifdef _WIN32
	#if defined(B_ADS_IMPORT)
		#define B_ADS_EXPORT_API __declspec(dllimport)
	#elif defined(B_ADS_EXPORT)
		#define B_ADS_EXPORT_API __declspec(dllexport)
	#else
		#define B_ADS_EXPORT_API
	#endif
#else
  #define B_ADS_EXPORT_API
#endif

// Use namespace
// Disabled with Qt4, it makes problems with signals and slots.
#ifdef B_ADS_NAMESPACE_ENABLED
	#define B_ADS_NAMESPACE_BEGIN namespace b_ads {
	#define B_ADS_NAMESPACE_END }
	#define B_ADS_NS ::b_ads
#else
	#define B_ADS_NAMESPACE_BEGIN
	#define B_ADS_NAMESPACE_END
	#define B_ADS_NS
#endif

// Always enable "serialization" namespace.
// It is not required for signals and slots.
#define B_ADS_NAMESPACE_SER_BEGIN namespace b_ads { namespace serialization {
#define B_ADS_NAMESPACE_SER_END }}
#define B_ADS_NS_SER ::b_ads::serialization

// Width of the native window frame border (based on OS).
#define B_ADS_WINDOW_FRAME_BORDER_WIDTH 7

// Beautiful C++ stuff.
#define B_ADS_Expects(cond)
#define B_ADS_Ensures(cond)

// Indicates whether ADS should include animations.
//#define ADS_ANIMATIONS_ENABLED 1
//#define ADS_ANIMATION_DURATION 150

B_ADS_NAMESPACE_BEGIN
class ContainerWidget;
class SectionWidget;

enum DropArea
{
	InvalidDropArea = 0,
	TopDropArea = 1,
	RightDropArea = 2,
	BottomDropArea = 4,
	LeftDropArea = 8,
	CenterDropArea = 16,

	AllAreas = TopDropArea | RightDropArea | BottomDropArea | LeftDropArea | CenterDropArea
};
Q_DECLARE_FLAGS(DropAreas, DropArea)

void deleteEmptySplitter(ContainerWidget* container);
ContainerWidget* findParentContainerWidget(QWidget* w);
SectionWidget* findParentSectionWidget(QWidget* w);
QSplitter* findParentSplitter(QWidget* w);
QSplitter* findImmediateSplitter(QWidget* w);

B_ADS_NAMESPACE_END
