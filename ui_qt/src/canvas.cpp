#include <dak/ui/qt/canvas.h>

#include <dak/ui/qt/painter_drawing.h>

#include <QtGui/qpainter.h>
#include <QtCore/qcoreevent.h>

namespace dak::ui::qt
{
   ////////////////////////////////////////////////////////////////////////////
   //
   // A QWidget that brings together a transformer and widget emitter
   // with some transformable to be provided by a sub-class.

   canvas_t::canvas_t(QWidget* parent)
   : QWidget(parent)
   , transformer([this](transformer_t& trfer) { paint_transformer(); })
   , emi(*this)
   {
      emi.event_receivers.push_back(&transformer);
      setContentsMargins(0, 0, 0, 0);
   }

   canvas_t::canvas_t(QWidget* parent, ui::transformable_t& trfable)
   : canvas_t(parent)
   {
      transformer.manipulated = &trfable;
   }

   void canvas_t::paintEvent(QPaintEvent * pe)
   {
      QPainter painter(this);
      painter.setRenderHint(QPainter::RenderHint::Antialiasing);
      painter.setRenderHint(QPainter::RenderHint::TextAntialiasing);
      painter.setRenderHint(QPainter::RenderHint::SmoothPixmapTransform);

      paint(painter);
   }

   void canvas_t::paint(QPainter& painter)
   {
      painter_drawing_t trfer_drawing(painter);
      transformer.draw(trfer_drawing);
   }

   void canvas_t::paint_transformer()
   {
      update();

      if (redraw_timer)
      {
         killTimer(redraw_timer);
         redraw_timer = 0;
      }

      redraw_timer = startTimer(700);
   }
   void canvas_t::timerEvent(QTimerEvent* te)
   {
      if (!te || te->timerId() != redraw_timer)
         return;

      transformer.end_interaction();

      update();
      redraw_timer = 0;
   }

}

// vim: sw=3 : sts=3 : et : sta : 
