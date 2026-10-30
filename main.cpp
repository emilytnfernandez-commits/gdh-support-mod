#include <Geode/Geode.hpp>

using namespace geode::prelude;

// Ejemplo de un hook básico en el menú principal para verificar que compila
#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }
        
        log::info("¡GDH Support Mod cargado correctamente en Windows!");
        return true;
    }
};
