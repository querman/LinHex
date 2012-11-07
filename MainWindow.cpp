#include "MainWindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>

namespace Linhex {

    MainWindow::MainWindow() : QMainWindow() {
        createActions();
        createMenus();
        createContextMenu();
        createToolBars();
        createStatusBar();
    }

    void MainWindow::closeEvent(QCloseEvent *event) {
    }

    void MainWindow::createActions() {
        openAction = new QAction(tr("Open"), this);
        openAction->setIcon(QIcon(":/images/open"));
        openAction->setShortcut(QKeySequence::Open);
        connect(openAction, SIGNAL(triggered()), this, SIGNAL(openSignal()));
        saveAction = new QAction(tr("Save"), this);
        saveAction->setIcon(QIcon(":/images/save"));
        saveAction->setShortcut(QKeySequence::Save);
        connect(saveAction, SIGNAL(triggered()), this, SIGNAL(saveSignal()));
        saveAsAction = new QAction(tr("Save As..."), this);
        saveAsAction->setShortcut(QKeySequence::SaveAs);
        connect(saveAsAction, SIGNAL(triggered()), this, SIGNAL(saveAsSignal()));
        saveAsHtmlAction = new QAction(tr("Save As HTML..."), this);
        saveAsHtmlAction->setIcon(QIcon(":/images/html"));
        connect(saveAsHtmlAction, SIGNAL(triggered()), this, SIGNAL(saveAsHtmlSignal()));
        revertAction = new QAction(tr("Revert"), this);
        connect(revertAction, SIGNAL(triggered()), this, SIGNAL(revertSignal()));
        printAction = new QAction(tr("Print"), this);
        printAction->setIcon(QIcon(":/images/print"));
        printAction->setShortcut(QKeySequence::Print);
        connect(printAction, SIGNAL(triggered()), this, SIGNAL(printSignal()));
        printPreviewAction = new QAction(tr("Print Previe&w..."), this);
        printPreviewAction->setShortcut(tr("Ctrl+Shift+P"));
        printPreviewAction->setIcon(QIcon(":/images/print_preview"));
        connect(printPreviewAction, SIGNAL(triggered()), this, SIGNAL(printPreviewSignal()));
        for (int i = 0; i < MAX_RECENT_FILE; i++) {
            recentFileActions[i] = new QAction(this);
            recentFileActions[i]->setIcon(QIcon(":/images/recent_file"));
            recentFileActions[i]->setVisible(false);
            connect(recentFileActions[i], SIGNAL(triggered()), this, SIGNAL(recentFilesSignal()));
        }
        closeAction = new QAction(tr("&Close"), this);
        closeAction->setShortcut(tr("Ctrl+W"));
        connect(closeAction, SIGNAL(triggered()), this, SIGNAL(closeSignal()));
        exitAction = new QAction(tr("E&xit"), this);
        exitAction->setShortcut(tr("Ctrl+Q"));
        connect(exitAction, SIGNAL(triggered()), this, SIGNAL(exitSignal()));
        undoAction = new QAction(tr("Undo"), this);
        undoAction->setIcon(QIcon(":/images/undo"));
        undoAction->setShortcut(QKeySequence::Undo);
        connect(undoAction, SIGNAL(triggered()), this, SIGNAL(undoSignal()));
        redoAction = new QAction(tr("Redo"), this);
        redoAction->setIcon(QIcon(":/images/redo"));
        redoAction->setShortcut(QKeySequence::Redo);
        connect(redoAction, SIGNAL(triggered()), this, SIGNAL(redoSignal()));
        copyAction = new QAction(tr("Copy"), this);
        copyAction->setIcon(QIcon(":/images/copy"));
        copyAction->setShortcut(QKeySequence::Copy);
        connect(copyAction, SIGNAL(triggered()), this, SIGNAL(copySignal()));
        cutAction = new QAction(tr("Cut"), this);
        cutAction->setIcon(QIcon(":/images/cut"));
        cutAction->setShortcut(QKeySequence::Cut);
        connect(cutAction, SIGNAL(triggered()), this, SIGNAL(cutSignal()));
        pasteAction = new QAction(tr("Paste"), this);
        pasteAction->setIcon(QIcon(":/images/paste"));
        pasteAction->setShortcut(QKeySequence::Paste);
        connect(pasteAction, SIGNAL(triggered()), this, SIGNAL(pasteSignal()));
        findAction = new QAction(tr("Find"), this);
        findAction->setIcon(QIcon(":/images/find"));
        findAction->setShortcut(QKeySequence::Find);
        connect(findAction, SIGNAL(triggered()), this, SIGNAL(findSignal()));
        advanceFindAction = new QAction(tr("Advance Find"), this);
        advanceFindAction->setIcon(QIcon(":/images/advance_find"));
        connect(advanceFindAction, SIGNAL(triggered()), this, SIGNAL(advanceFindeSignal()));
        replaceAction = new QAction(tr("Replace"), this);
        replaceAction->setIcon(QIcon(":/images/replace"));
        replaceAction->setShortcut(QKeySequence::Replace);
        connect(replaceAction, SIGNAL(triggered()), this, SIGNAL(replaceSignal()));
        goToByteAction = new QAction(tr("Go To Byte"), this);
        goToByteAction->setIcon(QIcon(":/images/go_to_byte"));
        connect(goToByteAction, SIGNAL(triggered()), this, SIGNAL(goToByteSignal()));
        insertModeAction = new QAction(tr("Insert Mode"), this);
        connect(insertModeAction, SIGNAL(triggered()), this, SIGNAL(insertModeSignal()));
        preferencesAction = new QAction(tr("Preferences"), this);
        preferencesAction->setIcon(QIcon(":/images/preferences"));
        preferencesAction->setShortcut(QKeySequence::Preferences);
        connect(preferencesAction, SIGNAL(triggered()), this, SIGNAL(preferencesSignal()));
        addViewAction = new QAction(tr("Add View"), this);
        connect(addViewAction, SIGNAL(triggered()), this, SIGNAL(addViewSignal()));
        removeViewAction = new QAction(tr("Remove View"), this);
        connect(removeViewAction, SIGNAL(triggered()), this, SIGNAL(removeViewSignal()));
        groupAsDataActionGroup = new QActionGroup(this);
        byteAction = new QAction(tr("Bytes"), this);
        byteAction->setCheckable(true);
        byteAction->setActionGroup(groupAsDataActionGroup);
        connect(byteAction, SIGNAL(triggered()), this, SIGNAL(selectByteSignal()));
        wordAction = new QAction(tr("Words"), this);
        wordAction->setCheckable(true);
        wordAction->setActionGroup(groupAsDataActionGroup);
        connect(wordAction, SIGNAL(triggered()), this, SIGNAL(selectWordSignal()));
        longwordsAction = new QAction(tr("Longwords"), this);
        longwordsAction->setCheckable(true);
        longwordsAction->setActionGroup(groupAsDataActionGroup);
        connect(longwordsAction, SIGNAL(triggered()), this, SIGNAL(selectLongwordsSignal()));
        charTableAction = new QAction(tr("Character Table"), this);
        charTableAction->setCheckable(true);
        connect(charTableAction, SIGNAL(triggered()), this, SIGNAL(charTableSignal()));
        baseConverterAction = new QAction(tr("Base Converter"), this);
        baseConverterAction->setCheckable(true);
        connect(baseConverterAction, SIGNAL(triggered()), this, SIGNAL(baseConverterSignal()));
        typeConversationAction = new QAction(tr("Type Conversation"), this);
        typeConversationAction->setCheckable(true);
        connect(typeConversationAction, SIGNAL(triggered()), this, SIGNAL(typeConversationSignal()));
        contentAction = new QAction(tr("Content"), this);
        contentAction->setIcon(QIcon(":/images/content"));
        contentAction->setShortcut(QKeySequence::HelpContents);
        connect(contentAction, SIGNAL(triggered()), this, SIGNAL(contentSignal()));
        aboutAction = new QAction(tr("About"), this);
        connect(aboutAction, SIGNAL(triggered()), this, SIGNAL(aboutSignal()));
    }

    void MainWindow::createMenus() {
        fileMenu = menuBar()->addMenu(tr("&File"));
        fileMenu->addAction(openAction);
        fileMenu->addAction(saveAction);
        fileMenu->addAction(saveAsAction);
        fileMenu->addAction(saveAsHtmlAction);
        fileMenu->addSeparator();
        fileMenu->addAction(revertAction);
        fileMenu->addSeparator();
        fileMenu->addAction(printAction);
        fileMenu->addAction(printPreviewAction);
        for (int i = 0; i < MAX_RECENT_FILE; i++) {
            fileMenu->addAction(recentFileActions[i]);
        }
        fileMenu->addSeparator();
        fileMenu->addAction(closeAction);
        fileMenu->addAction(exitAction);
        editMenu = menuBar()->addMenu(tr("&Edit"));
        editMenu->addAction(undoAction);
        editMenu->addAction(redoAction);
        editMenu->addSeparator();
        editMenu->addAction(copyAction);
        editMenu->addAction(cutAction);
        editMenu->addAction(pasteAction);
        editMenu->addSeparator();
        editMenu->addAction(findAction);
        editMenu->addAction(advanceFindAction);
        editMenu->addSeparator();
        editMenu->addAction(replaceAction);
        editMenu->addAction(goToByteAction);
        editMenu->addAction(insertModeAction);
        editMenu->addSeparator();
        editMenu->addAction(preferencesAction);
        viewMenu = menuBar()->addMenu(tr("&View"));
        viewMenu->addAction(addViewAction);
        viewMenu->addAction(removeViewAction);
        groupAsDataMenu = viewMenu->addMenu(tr("Group As Data"));
        groupAsDataMenu->addAction(byteAction);
        groupAsDataMenu->addAction(wordAction);
        groupAsDataMenu->addAction(longwordsAction);
        windowsMenu = menuBar()->addMenu(tr("&Windows"));
        windowsMenu->addAction(charTableAction);
        windowsMenu->addAction(baseConverterAction);
        windowsMenu->addAction(typeConversationAction);
        helpMenu = menuBar()->addMenu(tr("&Help"));
        helpMenu->addAction(contentAction);
        helpMenu->addAction(aboutAction);
    }

    void MainWindow::createContextMenu() {
        // TODO create context menu
    }

    void MainWindow::createToolBars() {
        fileToolBar = addToolBar(tr("&File"));
        fileToolBar->addAction(openAction);
        fileToolBar->addAction(saveAction);
        fileToolBar->addAction(saveAsHtmlAction);
        fileToolBar->addAction(printAction);
        fileToolBar->addAction(printPreviewAction);
        editToolBar = addToolBar(tr("&Edit"));
        editToolBar->addAction(undoAction);
        editToolBar->addAction(redoAction);
        editToolBar->addAction(copyAction);
        editToolBar->addAction(cutAction);
        editToolBar->addAction(pasteAction);
        editToolBar->addAction(findAction);
        editToolBar->addAction(advanceFindAction);
        editToolBar->addAction(replaceAction);
        editToolBar->addAction(goToByteAction);
        editToolBar->addAction(preferencesAction);
        helpToolBar = addToolBar(tr("Help"));
        helpToolBar->addAction(contentAction);
    }

    void MainWindow::createStatusBar() {
        offsetLabel = new QLabel("99999999");
        offsetLabel->setAlignment(Qt::AlignCenter);
        offsetLabel->setMinimumSize(offsetLabel->sizeHint());

        selectionLabel = new QLabel();
        selectionLabel->setIndent(3);

        statusBar()->addWidget(offsetLabel);
        statusBar()->addWidget(selectionLabel,1);
    }

}


