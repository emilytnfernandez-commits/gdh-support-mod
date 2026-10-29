#include <Geode/Geode.hpp>
#include <random>
#include <string>

using namespace geode::prelude;

// Genera un verify code de 6 caracteres al azar (números, mayúsculas y minúsculas).
static std::string makeVerifyCode() {
	static const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	std::random_device rd;
	std::uniform_int_distribution<size_t> pick(0, sizeof(chars) - 2);
	std::string code;
	for (int i = 0; i < 6; ++i) code += chars[pick(rd)];
	return code;
}

// Construye el texto de un .gdh con tu formato:
// ID; Objetos; User (me); Verify code; contraseña repetida dos veces.
static std::string buildGdh(int levelId, int objects, std::string const& user,
                            std::string const& verifyCode, std::string const& password) {
	return "ID; " + std::to_string(levelId) + "\n" +
	       "Objetos; " + std::to_string(objects) + "\n" +
	       "User; " + user + " (me)\n" +
	       "Verify code; " + verifyCode + "\n" +
	       password + "\n" +
	       password + "\n";
}

// Guarda el .gdh en la carpeta de datos del mod.
static void exportGdh(int levelId, int objects, std::string const& user, std::string const& password) {
	auto text = buildGdh(levelId, objects, user, makeVerifyCode(), password);
	auto path = Mod::get()->getSaveDir() / (std::to_string(levelId) + ".gdh");
	auto res = utils::file::writeString(path, text);
	if (res.isErr()) log::error("No se pudo guardar el .gdh: {}", res.unwrapErr());
	else log::info("Guardado {}", path.string());
}

$on_mod(Loaded) {
	log::info("GDH Support Mod cargado");
	// TODO: añadir un botón en el editor o en la pantalla del nivel (con Node IDs)
	//       que llame a exportGdh(...) con el ID, el nº de objetos y la contraseña del nivel.
	// TODO: bloquear el nivel con contraseña ("password level blocked").
	// TODO: enviar el verify code a tu servidor para que lo valide.
	(void)exportGdh;
}
