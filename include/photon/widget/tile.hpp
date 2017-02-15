/*=======================================================================================
   Copyright (c) 2016-2017 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=======================================================================================*/
#if !defined(PHOTON_GUI_LIB_WIDGET_TILE_APRIL_13_2016)
#define PHOTON_GUI_LIB_WIDGET_TILE_APRIL_13_2016

#include <photon/widget/composite.hpp>
#include <memory>

namespace photon
{
   //////////////////////////////////////////////////////////////////////////////////////
   // Vertical Tiles
   //////////////////////////////////////////////////////////////////////////////////////
   class vtile_widget : public composite_base
   {
   public:

      virtual widget_limits   limits(basic_context const& ctx) const;
      virtual void            layout(context const& ctx);
      virtual rect            bounds_of(context const& ctx, std::size_t index) const;

   private:

      std::vector<float>      _tiles;
      float                   _left;
      float                   _right;
   };

   using vtile_composite = vector_composite<vtile_widget>;

   template <typename... W>
   inline auto vtile(W&&... elements)
   {
      array_composite<sizeof...(elements), vtile_widget> r{};
      r = {{ share(std::forward<W>(elements))... }};
      return r;
   }

   //////////////////////////////////////////////////////////////////////////////////////
   // Horizontal Tiles
   //////////////////////////////////////////////////////////////////////////////////////
   class htile_widget : public composite_base
   {
   public:

      virtual widget_limits   limits(basic_context const& ctx) const;
      virtual void            layout(context const& ctx);
      virtual rect            bounds_of(context const& ctx, std::size_t index) const;

   private:

      std::vector<float>      _tiles;
      float                   _top;
      float                   _bottom;
   };

   using htile_composite = vector_composite<htile_widget>;

   template <typename... W>
   inline auto htile(W&&... elements)
   {
      array_composite<sizeof...(elements), htile_widget> r{};
      r = {{ share(std::forward<W>(elements))... }};
      return r;
   }
}

#endif
