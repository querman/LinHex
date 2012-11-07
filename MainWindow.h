#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QActionGroup;
class QLabel;

namespace Linhex {

    class MainWindow: public QMainWindow {

            Q_OBJECT

        public: //Public methods
            MainWindow();

        protected: // Protected methods
            void closeEvent(QCloseEvent *event);

        private: // Private methods
            void createActions();
            void createMenus();
            void createContextMenu();
            void createToolBars();
            void createStatusBar();

        private: // Private class variables
            static const int MAX_RECENT_FILE = 5;
            QAction *openAction;
            QAction *saveAction;
            QAction *saveAsAction;
            QAction *saveAsHtmlAction;
            QAction *revertAction;
            QAction *printAction;
            QAction *printPreviewAction;
            QAction *recentFileActions[MAX_RECENT_FILE];
            QAction *closeAction;
            QAction *exitAction;
            QAction *undoAction;
            QAction *redoAction;
            QAction *copyAction;
            QAction *cutAction;
            QAction *pasteAction;
            QAction *findAction;
            QAction *advanceFindAction;
            QAction *replaceAction;
            QAction *goToByteAction;
            QAction *insertModeAction;
            QAction *preferencesAction;
            QAction *addViewAction;
            QAction *removeViewAction;
            QAction *byteAction;
            QAction *wordAction;
            QAction *longwordsAction;
            QActionGroup *groupAsDataActionGroup;
            QAction *charTableAction;
            QAction *baseConverterAction;
            QAction *typeConversationAction;
            QAction *contentAction;
            QAction *aboutAction;
            QMenu *fileMenu;
            QMenu *editMenu;
            QMenu *viewMenu;
            QMenu *groupAsDataMenu;
            QMenu *windowsMenu;
            QMenu *helpMenu;
            QToolBar *fileToolBar;
            QToolBar *editToolBar;
            QToolBar *helpToolBar;
            QLabel *offsetLabel;
            QLabel *selectionLabel;

        signals: // Signals
            void openSignal();
            void saveSignal();
            void saveAsSignal();
            void saveAsHtmlSignal();
            void revertSignal();
            void printSignal();
            void printPreviewSignal();
            void recentFilesSignal();
            void closeSignal();
            void exitSignal();
            void undoSignal();
            void redoSignal();
            void copySignal();
            void cutSignal();
            void pasteSignal();
            void findSignal();
            void advanceFindeSignal();
            void replaceSignal();
            void goToByteSignal();
            void insertModeSignal();
            void preferencesSignal();
            void addViewSignal();
            void removeViewSignal();
            void selectByteSignal();
            void selectWordSignal();
            void selectLongwordsSignal();
            void charTableSignal();
            void baseConverterSignal();
            void typeConversationSignal();
            void contentSignal();
            void aboutSignal();

    };
}
#endif // MAINWINDOW_H
