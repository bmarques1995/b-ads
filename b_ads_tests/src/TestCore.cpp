#include "TestCore.h"

#include "API.h"
#include "Serialization.h"

void TestCore::serialization()
{
	QList<QByteArray> datas;
	datas.append(QByteArray("Custom Data Here!!!"));
	datas.append(QByteArray("Even More..."));
	datas.append(QByteArray("lalalaalalalalalalal").toBase64());

	// WRITE some data.
	B_ADS_NS_SER::InMemoryWriter writer;
	for (int i = 0; i < datas.count(); ++i)
	{
		QVERIFY(writer.write(B_ADS_NS_SER::ET_Custom + i, datas.at(i)));
	}

	// Type: SectionIndexData
	B_ADS_NS_SER::SectionIndexData sid;
	for (int i = 0; i < 1; ++i)
	{
		B_ADS_NS_SER::SectionEntity se;
		se.x = i;
		se.y = i;
		se.width = 100 + i;
		se.height = 100 + i;
		se.currentIndex = i;

		for (int j = 0; j < 1; ++j)
		{
			B_ADS_NS_SER::SectionContentEntity sce;
			sce.uniqueName = QString("uname-%1-%2").arg(i).arg(j);
			sce.preferredIndex = 8;
			sce.visible = true;
			se.sectionContents.append(sce);
			se.sectionContentsCount += 1;
		}

		sid.sections.append(se);
		sid.sectionsCount += 1;
	}
	QVERIFY(writer.write(sid));

	QVERIFY(writer.offsetsCount() == datas.count() + 1);
	const QByteArray writtenData = writer.toByteArray();
	QVERIFY(writtenData.size() > 0);

	// READ and validate written data.
	B_ADS_NS_SER::InMemoryReader reader(writtenData);
	QVERIFY(reader.initReadHeader());
	QVERIFY(reader.offsetsCount() == datas.count() + 1);
	for (int i = 0; i < datas.count(); ++i)
	{
		QByteArray readData;
		QVERIFY(reader.read(B_ADS_NS_SER::ET_Custom + i, readData));
		QVERIFY(readData == datas.at(i));
	}

	// Type: SectionIndexData
	B_ADS_NS_SER::SectionIndexData sidRead;
	QVERIFY(reader.read(sidRead));

	// TODO compare sidRead with sid
}

QTEST_MAIN(TestCore)