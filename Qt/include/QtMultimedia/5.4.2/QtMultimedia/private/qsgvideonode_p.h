/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia. For licensing terms and
** conditions see http://qt.digia.com/licensing. For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSGVIDEONODE_P_H
#define QSGVIDEONODE_P_H

#include <QtQuick/qsgnode.h>
#include <private/qtmultimediaquickdefs_p.h>

#include <QtMultimedia/qvideoframe.h>
#include <QtMultimedia/qvideosurfaceformat.h>
#include <QtGui/qopenglfunctions.h>

QT_BEGIN_NAMESPACE

class Q_MULTIMEDIAQUICK_EXPORT QSGVideoNode : public QSGGeometryNode
{
public:
    QSGVideoNode();

    virtual void setCurrentFrame(const QVideoFrame &frame) = 0;
    virtual QVideoFrame::PixelFormat pixelFormat() const = 0;

    void setTexturedRectGeometry(const QRectF &boundingRect, const QRectF &textureRect, int orientation);

private:
    QRectF m_rect;
    QRectF m_textureRect;
    int m_orientation;
};

class Q_MULTIMEDIAQUICK_EXPORT QSGVideoNodeFactoryInterface
{
public:
    virtual QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const = 0;
    virtual QSGVideoNode *createNode(const QVideoSurfaceFormat &format) = 0;
};

#define QSGVideoNodeFactoryInterface_iid "org.qt-project.qt.sgvideonodefactory/5.2"
Q_DECLARE_INTERFACE(QSGVideoNodeFactoryInterface, QSGVideoNodeFactoryInterface_iid)

class Q_MULTIMEDIAQUICK_EXPORT QSGVideoNodeFactoryPlugin : public QObject, public QSGVideoNodeFactoryInterface
{
    Q_OBJECT
    Q_INTERFACES(QSGVideoNodeFactoryInterface)
public:
    virtual QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const = 0;
    virtual QSGVideoNode *createNode(const QVideoSurfaceFormat &format) = 0;
};

QT_END_NAMESPACE

#endif // QSGVIDEONODE_H
