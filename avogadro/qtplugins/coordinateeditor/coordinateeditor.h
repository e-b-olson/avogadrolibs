/******************************************************************************
  This source file is part of the Avogadro project.
  This source code is released under the 3-Clause BSD License, (see "LICENSE").
******************************************************************************/

#ifndef AVOGADRO_QTPLUGINS_COORDINATEEDITOR_H
#define AVOGADRO_QTPLUGINS_COORDINATEEDITOR_H

#include <avogadro/qtgui/extensionplugin.h>
#include <avogadro/core/avogadrocore.h>
#include <qlist.h>
#include <qobjectdefs.h>
#include <qstring.h>
#include <qstringlist.h>

class QAction;
class QObject;

namespace Avogadro {
namespace QtGui {
class Molecule;
}  // namespace QtGui

namespace QtPlugins {
class CoordinateEditorDialog;

/**
 * @brief CoordinateEditor implements the plugin interface for the coordinate
 * editor extension.
 */
class CoordinateEditor : public Avogadro::QtGui::ExtensionPlugin
{
  Q_OBJECT
public:
  explicit CoordinateEditor(QObject* parent_ = nullptr);
  ~CoordinateEditor() override;

  QString name() const override { return tr("Coordinate editor"); }

  QString description() const override
  {
    return tr("Text editing of atomic coordinates.");
  }

  QList<QAction*> actions() const override;

  QStringList menuPath(QAction* action) const override;

public slots:
  void setMolecule(QtGui::Molecule* mol) override;

private slots:
  void triggered();
  void pastedMolecule();

private:
  CoordinateEditorDialog* m_dialog;
  QtGui::Molecule* m_molecule;
  QAction* m_action;
};

} // namespace QtPlugins
} // namespace Avogadro

#endif // AVOGADRO_QTPLUGINS_COORDINATEEDITOR_H
