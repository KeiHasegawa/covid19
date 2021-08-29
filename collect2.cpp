#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>
#include <cassert>
#include <numeric>

enum class Prefectures {
  Tokyo,
  Kanagawa,
  Saitama,
  Chiba,
  Ibaraki,
  Tochigi,
  Gunma,
  Osaka,
  Hyougo,
  Nara,
  Kyoto,
  Wakayama,
  Shiga,
};

struct info_t {
  int id;
  std::string place;
  std::pair<double, double> coord;
  Prefectures pref;
};

std::vector<info_t> data = {
  {533946114, "Nihonbashi", {35.68123,139.774534}, Prefectures::Tokyo},
  {533946113, "Marunouchi", {35.680478,139.765367}, Prefectures::Tokyo},
  {533946211, "Ootemachi", {35.687438,139.764955}, Prefectures::Tokyo},
  {533946013, "Ginza", {35.669626,139.765539}, Prefectures::Tokyo},
  {533936904, "Shinbashi", {35.664917,139.757003}, Prefectures::Tokyo},
  {533946001, "Toranomon", {35.665949,139.74625}, Prefectures::Tokyo},
  {533946411, "Ochanomizu", {35.718733,139.731683}, Prefectures::Tokyo},
  {533946521, "Ueno", {35.711622,139.775695}, Prefectures::Tokyo},
  {533946532, "Asakusa", {35.717064,139.79875}, Prefectures::Tokyo},
  {533946542, "Skytree", {35.710063,139.8107}, Prefectures::Tokyo},
  {533946353, "Kinshicho", {35.698312,139.813998}, Prefectures::Tokyo},
  {533936834, "Toyosu", {35.652026,139.788785}, Prefectures::Tokyo},
  {533936833, "RaraportToyosu", {35.655735,139.792662}, Prefectures::Tokyo},
  {533935981, "Roppongi", {35.662893,139.733651}, Prefectures::Tokyo},
  {533935961, "Shibuya", {35.661633,139.702516}, Prefectures::Tokyo},
  {533935952, "Centergai", {35.658034,139.701636}, Prefectures::Tokyo},
  {533935853, "Kamiizumi", {35.65727,139.693623}, Prefectures::Tokyo},
  {533945052, "Yoyogikouen", {35.671587,139.696703}, Prefectures::Tokyo},
  {533945254, "ShinjukuNishi", {35.693292,139.699132}, Prefectures::Tokyo},
  {533945263, "ShinjukuHigashi", {35.689607,139.700571}, Prefectures::Tokyo},
  {533945361, "Kabukicho", {35.695543,139.703149}, Prefectures::Tokyo},
  {533945764, "Ikebukuro", {35.736262,139.707009}, Prefectures::Tokyo},
  {533945433, "Nakano", {35.70607,139.659262}, Prefectures::Tokyo},
  {533945963, "Ohyamaeki", {35.748531,139.702286}, Prefectures::Tokyo},
  {533946712, "Nippori", {35.728158,139.770641}, Prefectures::Tokyo},
  {533946943, "Kitasenju", {35.753029,139.803752}, Prefectures::Tokyo},
  {533936521, "Daiba", {35.61885,139.780188}, Prefectures::Tokyo},
  {533935591, "Shinagawa", {35.628471,139.73876}, Prefectures::Tokyo},
  {533935481, "Ohsaki", {35.619851,139.728189}, Prefectures::Tokyo},
  {533925771, "Kamata", {35.562479,139.716073}, Prefectures::Tokyo},
  {533926524, "Haneda", {35.549393,139.779839}, Prefectures::Tokyo},
  {533935732, "Sangenchaya", {35.641285,139.667989,}, Prefectures::Tokyo},
  {533932873, "Hachioji", {35.658566,139.295838}, Prefectures::Tokyo},
  {533933931, "Takahatahudo", {35.662013,139.411074}, Prefectures::Tokyo},
  {533943083, "Huchu", {35.673204,139.477815}, Prefectures::Tokyo},
  {533934601, "Inagi", {35.628468,139.494632}, Prefectures::Tokyo},
  {533934832, "Chohu", {35.660425,139.555081}, Prefectures::Tokyo},
  {533934662, "Kitami", {35.636547,139.587245}, Prefectures::Tokyo},
  {533944494, "Ogikubo", {35.697402,139.622517}, Prefectures::Tokyo},
  {533944461, "Kichijoji", {35.703158,139.580115}, Prefectures::Tokyo},
  {533944442, "Mitaka", {35.683546,139.559268}, Prefectures::Tokyo},
  {533944402, "MusashiKoganei", {35.701123,139.506912}, Prefectures::Tokyo},
  {533943481, "Kokubunji", {35.705538,139.460007}, Prefectures::Tokyo},
  {533943333, "Tachikawa", {35.714188,139.399159}, Prefectures::Tokyo},
  {533942584, "Akishima", {35.708829,139.364915}, Prefectures::Tokyo},
  {533942722, "Akikawa", {35.728027,139.286749}, Prefectures::Tokyo},
  {533942902, "Hinodecho", {35.742117,139.257405}, Prefectures::Tokyo},
  {533942961, "Hussa", {35.742364,139.327865}, Prefectures::Tokyo},
  {533952274, "Hakonesaki", {35.771312,139.346714}, Prefectures::Tokyo},
  {533952341, "Kosaku", {35.777083,139.303125}, Prefectures::Tokyo},
  {533952422, "Kawabe", {35.785417,139.284375}, Prefectures::Tokyo},
  {533954214, "Kiyose", {35.784283,139.521967}, Prefectures::Tokyo},
  {533954122, "Higashikurume", {35.753218,139.516371}, Prefectures::Tokyo},
  {533943974, "Kumekawa", {35.750026,139.472007}, Prefectures::Tokyo},
  {533944731, "Tanashi", {35.727083,139.540625}, Prefectures::Tokyo},
  {533943683, "Hitotsubashigakuen", {35.72206,139.480039}, Prefectures::Tokyo},
  {533945821, "Nerima", {35.735785,139.651776}, Prefectures::Tokyo},
  {533955372, "Akabane", {35.783721,139.7217}, Prefectures::Tokyo},
  {533956174, "Kameari", {35.761606,139.848806}, Prefectures::Tokyo},
  {533936984, "Nishikasai", {35.664577,139.859203}, Prefectures::Tokyo},

  {533925354, "Kawasaki", {35.532988,139.700872}, Prefectures::Kanagawa},
  {533925363, "KeikyuKawasaki", {35.531365,139.696889}, Prefectures::Kanagawa},
  {533925141, "Tsurumi", {35.508036,139.676262}, Prefectures::Kanagawa},
  {533924191, "Shinyokohama", {35.508043,139.614786}, Prefectures::Kanagawa},
  {533915603, "Kanagawaeki", {35.471027,139.627114}, Prefectures::Kanagawa},
  {533914594, "Yokohama", {35.465981,139.622062}, Prefectures::Kanagawa},
  {533915313, "NipponOhdouri", {35.446456,139.642306}, Prefectures::Kanagawa},
  {533914474, "Hoshikawa", {35.458875,139.589907}, Prefectures::Kanagawa},
  {533914291, "Yoshinocho", {35.435417,139.615625}, Prefectures::Kanagawa},
  {533904972, "Kamiohoka", {35.409122,139.596629}, Prefectures::Kanagawa},
  {533904192, "Kanazawabunko", {35.343905,139.628711}, Prefectures::Kanagawa},
  {523974841, "Kamakura", {35.319065,139.550412}, Prefectures::Kanagawa},
  {523975332, "Yokosukachuo", {35.278699,139.67004}, Prefectures::Kanagawa},
  {523965223, "Miurakaiganeki", {35.188364,139.653511}, Prefectures::Kanagawa},
  {523974561, "Shinzushi", {35.295934,139.581199}, Prefectures::Kanagawa},
  {523974264, "Hayamacho", {35.272094,139.586202}, Prefectures::Kanagawa},
  {533903084, "Hujisawa", {35.338898,139.48747}, Prefectures::Kanagawa},
  {533904224, "Oohuna", {35.354048,139.531299}, Prefectures::Kanagawa},
  {533904822, "Totsuka", {35.400766,139.534204}, Prefectures::Kanagawa},
  {533904903, "Tateba", {35.414484,139.500994}, Prefectures::Kanagawa},
  {533903402, "Samukawacho", {35.37595,139.387012}, Prefectures::Kanagawa},
  {523973924, "Chigasaki", {35.330303,139.406817}, Prefectures::Kanagawa},
  {523972972, "Hiratsuka", {35.32783,139.350645}, Prefectures::Kanagawa},
  {523972751, "Ohiso", {35.311435,139.313291}, Prefectures::Kanagawa},
  {523972504, "Ninomiya", {35.298786,139.257598}, Prefectures::Kanagawa},
  {523971023, "Odawara", {35.256445,139.155393}, Prefectures::Kanagawa},
  {533902414, "Tokaidaigaku", {35.372872,139.270904}, Prefectures::Kanagawa},
  {533902753, "Isehara", {35.396037,139.313594}, Prefectures::Kanagawa},
  {533912293, "Hon-atsugi", {35.439408,139.364422}, Prefectures::Kanagawa},
  {533913411, "Ebina", {35.454271,139.389335}, Prefectures::Kanagawa},
  {533913662, "Yamato", {35.469831,139.461463}, Prefectures::Kanagawa},
  {533913682, "Seya", {35.473081,139.475668}, Prefectures::Kanagawa},
  {533913241, "Ayase", {35.437553,139.430111}, Prefectures::Kanagawa},
  {533923134, "OdakyuSagamihara", {35.515191,139.422653}, Prefectures::Kanagawa},
  {533923353, "Sagamiohno", {35.532641,139.433562}, Prefectures::Kanagawa},
  {533923552, "Machida", {35.541994,139.445376}, Prefectures::Kanagawa},
  {533924942, "Tamapraza", {35.577406,139.558528}, Prefectures::Kanagawa},
  {533924552, "CenterMinami", {35.545583,139.57451}, Prefectures::Kanagawa},
  {533925922, "MusashiKosugi", {35.576629,139.66}, Prefectures::Kanagawa},
  {533934071, "Miyazakidai", {35.587217,139.591201}, Prefectures::Kanagawa},
  {533934184, "Mizonokuchi", {35.599965,139.610623}, Prefectures::Kanagawa},
  {533934452, "Noborido", {35.620766,139.570098}, Prefectures::Kanagawa},
  {533934202, "Shinyuri", {35.603805,139.507605}, Prefectures::Kanagawa},
  {533923812, "Huchinobe", {35.568734,139.3951}, Prefectures::Kanagawa},
  {533932172, "Hashimoto", {35.594864,139.344922}, Prefectures::Kanagawa},
  {533922352, "Aikawacho", {35.528821,139.321661}, Prefectures::Kanagawa},
  {533933434, "Tamacenter", {35.623931,139.422853}, Prefectures::Kanagawa},
  {523971902, "Kaisei", {35.326485,139.135806}, Prefectures::Kanagawa},
  {523970882, "FujiFilmMaeeki", {35.317645,139.108928}, Prefectures::Kanagawa},
  {533900361, "Yamakitaeki", {35.360937,139.080372}, Prefectures::Kanagawa},
  {533901111, "Shinmatsuda", {35.344594,139.139444}, Prefectures::Kanagawa},
  {533901021, "SagamiKaneko", {35.333867,139.150462}, Prefectures::Kanagawa},
  {523951804, "Manazuru", {35.156809,139.13234}, Prefectures::Kanagawa},
  {523950783, "Yugawara", {35.146087,139.102177}, Prefectures::Kanagawa},
  {533914524, "Hutamatagawa", {35.463577,139.53231}, Prefectures::Kanagawa},
  {533924133, "Nakayama", {35.514752,139.539181}, Prefectures::Kanagawa},

  {533955671, "Kawaguchi", {35.833731,139.731689}, Prefectures::Saitama},
  {533955643, "Toda", {35.801922,139.66835}, Prefectures::Saitama},
  {533954493, "Wakou", {35.789853,139.62211}, Prefectures::Saitama},
  {533954642, "Niiza", {35.803692,139.556495}, Prefectures::Saitama},
  {533954764, "Asakasumidai", {35.814553,139.587081}, Prefectures::Saitama},
  {533964061, "Shigishi", {35.839701,139.581411}, Prefectures::Saitama},
  {533954921, "Miyoshicho", {35.833067,139.51686}, Prefectures::Saitama},
  {533964312, "Hujiminoshi", {35.867403,139.509741}, Prefectures::Saitama},
  {533964404, "Kamihukuokaeki", {35.873915,139.511741}, Prefectures::Saitama},
  {533963884, "Kawagoe", {35.907116,139.482444}, Prefectures::Saitama},
  {533974051, "Sashiohgieki", {35.91693,139.56494}, Prefectures::Saitama},
  {533953472, "Tokorozawa", {35.786617,139.473225}, Prefectures::Saitama},
  {533953004, "MusashiMurayama", {35.753403,139.384666}, Prefectures::Saitama},
  {533943833, "Sakurakaidoueki", {35.738918,139.416682}, Prefectures::Saitama},
  {533953833, "MusashiHujisawa", {35.820853,139.412763}, Prefectures::Saitama},
  {533955951, "Warabi", {35.824611,139.686419}, Prefectures::Saitama},
  {533956941, "Souka", {35.828478,139.803594}, Prefectures::Saitama},
  {533956674, "Yashio", {35.807836,139.844826}, Prefectures::Saitama},
  {533957803, "Misato", {35.825964,139.875843}, Prefectures::Saitama},
  {533966571, "Yoshikawa", {35.876664,139.843224}, Prefectures::Saitama},
  {533966531, "Koshigaya", {35.875611,139.789783}, Prefectures::Saitama},
  {533965363, "HigashiUrawa", {35.864132,139.704639}, Prefectures::Saitama},
  {533965322, "Urawa", {35.859044,139.657217}, Prefectures::Saitama},
  {533965112, "MusashiUrawa", {35.845957,139.647629}, Prefectures::Saitama},
  {533965101, "NishiUrawa", {35.844278,139.628025}, Prefectures::Saitama},
  {533965603, "Yono", {35.89078,139.628681}, Prefectures::Saitama},
  {533964894, "Ohmiya", {35.906449,139.623855}, Prefectures::Saitama},
  {533974284, "Miyaharaeki", {35.940292,139.609571}, Prefectures::Saitama},
  {533975313, "HigashiOhmiya", {35.948755,139.640286}, Prefectures::Saitama},
  {533975564, "Iwatsuki", {35.96334,139.712229}, Prefectures::Saitama},
  {533976703, "Kasukabe", {35.979918,139.752621}, Prefectures::Saitama},
  {533975723, "Hasuda", {35.981286,139.653069}, Prefectures::Saitama},
  {533974673, "Ageo", {35.973522,139.588818}, Prefectures::Saitama},
  {533974993, "Inachuo", {35.999422,139.61721}, Prefectures::Saitama},
  {533974953, "Okegawa", {35.998756,139.564032}, Prefectures::Saitama},
  {543904324, "Kitamoto", {36.031574,139.534009}, Prefectures::Saitama},
  {543904702, "Kounosu", {36.059241,139.509643}, Prefectures::Saitama},
  {543903463, "Yoshimicho", {36.039853,139.45373}, Prefectures::Saitama},
  {543903421, "HigashiMatsuyama", {36.034875,139.401776}, Prefectures::Saitama},
  {543903501, "ShinrinKoueneki", {36.045234,139.374902}, Prefectures::Saitama},
  {543902561, "MusashiArashiyama", {36.044381,139.32765}, Prefectures::Saitama},
  {543902031, "Meikakueki", {36.003341,139.288854}, Prefectures::Saitama},
  {543902702, "Ogawachoeki", {36.058417,139.261343}, Prefectures::Saitama},
  {543911451, "Yoriieki", {36.117887,139.194537}, Prefectures::Saitama},
  {543910382, "Nogamieki", {36.11159,139.111193}, Prefectures::Saitama},
  {543900981, "Oyahanaeki", {36.077566,139.106306}, Prefectures::Saitama},
  {533970962, "Ohanabatakeeki", {35.992492,139.083617}, Prefectures::Saitama},
  {533970872, "Yokose", {35.968188,139.132708}, Prefectures::Saitama},
  {533972534, "Ogose", {35.962165,139.299375}, Prefectures::Saitama},
  {533972361, "BushuNagaseeki", {35.941979,139.325765}, Prefectures::Saitama},
  {533973324, "Wakabaeki", {35.949105,139.40873}, Prefectures::Saitama},
  {533973614, "Kitasakado", {35.971836,139.396702}, Prefectures::Saitama},
  {543913344, "Gyoda", {36.113765,139.432249}, Prefectures::Saitama},
  {543913613, "Kumagaya", {36.13939,139.390033}, Prefectures::Saitama},
  {543924022, "Hanyu", {36.170361,139.534104}, Prefectures::Saitama},
  {543922224, "Hukaya", {36.191419,139.281398}, Prefectures::Saitama},
  {543921851, "Honjyo", {36.236164,139.188611}, Prefectures::Saitama},
  {543931012, "Jinbobara", {36.253464,139.149407}, Prefectures::Saitama},
  {543920583, "Tansou", {36.216661,139.102273}, Prefectures::Saitama},
  {543915302, "Hanasaki", {36.109925,139.633523}, Prefectures::Saitama},
  {543905873, "Satte", {36.074555,139.714949}, Prefectures::Saitama},
  {543905743, "Kuki", {36.065958,139.677633}, Prefectures::Saitama},
  {543905671, "SugidoTakanodai", {36.051502,139.714422}, Prefectures::Saitama},
  {543905283, "ToubuDoubutsuKouen", {36.02495,139.7267}, Prefectures::Saitama},
  {543905231, "Shiraoka", {36.017588,139.667094}, Prefectures::Saitama},
  {543924521, "Kawamataeki", {36.208923,139.526515}, Prefectures::Saitama},
  {543900202, "Oganocho", {36.01714,139.008604}, Prefectures::Saitama},

  {533937601, "DisneyLand", {35.632896,139.880394}, Prefectures::Chiba},
  {533947643, "Honyawata", {35.721091,139.927234}, Prefectures::Chiba},
  {533947482, "Hunabashi", {35.701736,139.985382}, Prefectures::Chiba},
  {534040214, "Tsudanuma", {35.691215,140.020407}, Prefectures::Chiba},
  {534030941, "KeiseiMakuhari", {35.660444,140.056076}, Prefectures::Chiba},
  {534030733, "KaihinMakuhari", {35.648476,140.041987}, Prefectures::Chiba},
  {534030673, "Inage", {35.63717,140.09249}, Prefectures::Chiba},
  {534031612, "Tsuga", {35.636095,140.149201}, Prefectures::Chiba},
  {534030391, "KeiseiChiba", {35.611618,140.114267}, Prefectures::Chiba},
  {534021741, "Kamatori", {35.562653,140.178736}, Prefectures::Chiba},
  {534020173, "Goieki", {35.513028,140.089701}, Prefectures::Chiba},
  {533917164, "Sodegaura", {35.432189,139.957829}, Prefectures::Chiba},
  {533907543, "Kisarazu", {35.381579,139.926229}, Prefectures::Chiba},
  {533907012, "Kimitsu", {35.333667,139.895042}, Prefectures::Chiba},
  {523976984, "Aobori", {35.330531,139.858939}, Prefectures::Chiba},
  {523956364, "Katsuyama", {35.114027,139.833394}, Prefectures::Chiba},
  {523956172, "Iwaieki", {35.09328,139.849893}, Prefectures::Chiba},
  {523936984, "Tateyama", {34.983579,139.846917}, Prefectures::Chiba},
  {524050283, "Kamogawa", {35.120034,140.073334}, Prefectures::Chiba},
  {524052842, "Katsuura", {35.152563,140.311936}, Prefectures::Chiba},
  {524062283, "Mishuku", {35.18756,140.351431}, Prefectures::Chiba},
  {524073011, "Ohara", {35.251221,140.391036}, Prefectures::Chiba},
  {534002493, "Ichinomiya", {35.373089,140.369527}, Prefectures::Chiba},
  {534012141, "Shigehara", {35.426874,140.304048}, Prefectures::Chiba},
  {534022244, "Ohami", {35.452607,140.282762}, Prefectures::Chiba},
  {534023451, "Kujuukuri", {35.522631,140.310999}, Prefectures::Chiba},
  {534022791, "Tougane", {35.560158,140.363609}, Prefectures::Chiba},
  {534033322, "Naritou", {35.608387,140.410859}, Prefectures::Chiba},
  {534033991, "Yokoshiba", {35.661769,140.491232}, Prefectures::Chiba},
  {534044343, "Youkaichi", {35.699286,140.552366}, Prefectures::Chiba},
  {534043331, "Shibayamacho", {35.693126,140.414397}, Prefectures::Chiba},
  {534032953, "Yachimata", {35.644488,140.301338}, Prefectures::Chiba},
  {534031933, "Yotsukaido", {35.666465,140.175374}, Prefectures::Chiba},
  {534041503, "Katsutadai", {35.715438,140.125972}, Prefectures::Chiba},
  {534041721, "Chikucentereki", {35.725856,140.155287}, Prefectures::Chiba},
  {534042723, "Sakesakai", {35.731664,140.275249}, Prefectures::Chiba},
  {534042771, "Miyazato", {35.726649,140.346981}, Prefectures::Chiba},
  {534043871, "Takocho", {35.74905,140.466227}, Prefectures::Chiba},
  {534053104, "Narita", {35.771987,140.39285}, Prefectures::Chiba},
  {534045623, "Asahi", {35.722009,140.654939}, Prefectures::Chiba},
  {534046763, "Choushi", {35.751212,140.7845}, Prefectures::Chiba},
  {534055861, "ShimousaTachibana", {35.780462,140.744675}, Prefectures::Chiba},
  {534061091, "Ajikieki", {35.835707,140.242358}, Prefectures::Chiba},
  {534050691, "ChibaNewtown", {35.800133,140.116274}, Prefectures::Chiba},
  {534050422, "Nishishiraieki", {35.784402,140.031767}, Prefectures::Chiba},
  {533957392, "Kamagaya", {35.779409,139.998398}, Prefectures::Chiba},
  {533957421, "Matsudo", {35.7843,139.900661}, Prefectures::Chiba},
  {533967372, "Kashiwa", {35.86215,139.970917}, Prefectures::Chiba},
  {534060404, "Abiko", {35.872703,140.010794}, Prefectures::Chiba},
  {533967443, "Nagareyama", {35.871905,139.925241}, Prefectures::Chiba},
  {533976491, "Atagoeki", {35.950148,139.864819}, Prefectures::Chiba},
  {533976151, "Matsubushicho", {35.922758,139.815748}, Prefectures::Chiba},

  // Ibaraki
  {534075601, "Kashima", {35.968807,140.631517}, Prefectures::Ibaraki},
  {534074232, "Itako", {35.937343,140.549606}, Prefectures::Ibaraki},
  {534073893, "Namekata", {35.993244,140.482587}, Prefectures::Ibaraki},
  {534072454, "Inashiki", {35.95472,140.326839}, Prefectures::Ibaraki},
  {534071113, "Sanuki", {35.930066,140.138229}, Prefectures::Ibaraki},
  {534060753, "Toride", {35.895699,140.062875}, Prefectures::Ibaraki},
  {533977491, "Moriya", {35.95067,139.992268}, Prefectures::Ibaraki},
  {534070931, "Miraidaira", {35.99375,140.040625}, Prefectures::Ibaraki},
  {544001024, "HitachinoUshiku", {36.007352,140.158247}, Prefectures::Ibaraki},
  {544001373, "Amicho", {36.030812,140.214808}, Prefectures::Ibaraki},
  {544001961, "Tsuchiura", {36.078484,140.206212}, Prefectures::Ibaraki},
  {544000984, "Tsukuba", {36.08251,140.11171}, Prefectures::Ibaraki},
  {543907291, "Mizukaidou", {36.018325,139.991993}, Prefectures::Ibaraki},
  {543907513, "Bandoushi", {36.048356,139.888837}, Prefectures::Ibaraki},
  {543916332, "Sakaicho", {36.108485,139.794953}, Prefectures::Ibaraki},
  {543927173, "Shimotsuma", {36.181994,139.96445}, Prefectures::Ibaraki},
  {543927113, "Yachiyocho", {36.181684,139.891121}, Prefectures::Ibaraki},
  {543936594, "Yuuki", {36.298223,139.872371}, Prefectures::Ibaraki},
  {543937681, "Shimodate", {36.304147,139.978334}, Prefectures::Ibaraki},
  {544040382, "Iwase", {36.359588,140.108271}, Prefectures::Ibaraki},
  {544041494, "Kasama", {36.373302,140.246142}, Prefectures::Ibaraki},
  {544053703, "Shirosato", {36.488544,140.307827}, Prefectures::Ibaraki},
  {544053954, "Uritura", {36.498221,140.449424}, Prefectures::Ibaraki},
  {544063533, "HitachiOomiya", {36.547132,140.412619}, Prefectures::Ibaraki},
  {544064323, "HitachOota", {36.531528,140.527906}, Prefectures::Ibaraki},
  {544054553, "Toukaieki", {36.465534,140.566054}, Prefectures::Ibaraki},
  {544043483, "Mito", {36.370755,140.476308}, Prefectures::Ibaraki},
  {544044712, "Katsuta", {36.39468,140.524589}, Prefectures::Ibaraki},
  {544034753, "Ooarai", {36.31505,140.562942}, Prefectures::Ibaraki},
  {544022924, "Hatori", {36.247523,140.286754}, Prefectures::Ibaraki},
  {544022223, "Ishioka", {36.19095,140.28025}, Prefectures::Ibaraki},
  {544014812, "Hokota", {36.152444,140.520298}, Prefectures::Ibaraki},
  {544075024, "Hitachi", {36.590439,140.661847}, Prefectures::Ibaraki},
  {554005573, "Takahagi", {36.714482,140.717003}, Prefectures::Ibaraki},
  {554012281, "HitachDaiko", {36.77094,140.3508}, Prefectures::Ibaraki},
  {554015494, "Isohara", {36.790502,140.746164}, Prefectures::Ibaraki},
  
  {543925362, "Koga", {36.194597,139.709555}, Prefectures::Tochigi},
  {543925784, "Nogi", {36.229954,139.734718}, Prefectures::Tochigi},
  {543933954, "Ashikaga", {36.331824,139.455877}, Prefectures::Tochigi},
  {543934861, "Sano", {36.316738,139.578856}, Prefectures::Tochigi},
  {543945063, "ShinOhirashita", {36.339024,139.701633}, Prefectures::Tochigi},
  {543936744, "Koyama", {36.313121,139.806324}, Prefectures::Tochigi},
  {543946781, "Jichiidaieki", {36.395411,139.854729}, Prefectures::Tochigi},
  {543957224, "Kamimikawa", {36.43922,139.909927}, Prefectures::Tochigi},
  {544050203, "Mouka", {36.439188,140.002576}, Prefectures::Tochigi},
  {544050573, "Mashiko", {36.463321,140.088886}, Prefectures::Tochigi},
  {544061344, "Mogi", {36.530794,140.181362}, Prefectures::Tochigi},
  {544060544, "Hagacho", {36.548215,140.058199}, Prefectures::Tochigi},
  {543956661, "Omochanomachi", {36.466668,139.829498}, Prefectures::Tochigi},
  {543965694, "Kanuma", {36.557266,139.744969}, Prefectures::Tochigi},
  {543967712, "Utsunomiya", {36.559023,139.898451}, Prefectures::Tochigi},
  {543977583, "Takarazumidera", {36.631476,139.979498}, Prefectures::Tochigi},
  {553907164, "Ujiie", {36.681632,139.962097}, Prefectures::Tochigi},
  {554030642, "Kuroiso", {36.9699,140.059446}, Prefectures::Tochigi},
  {554040294, "Nasucho", {37.01977,140.121006}, Prefectures::Tochigi},
  {553917644, "Yaita", {36.806617,139.932955}, Prefectures::Tochigi},
  {553905642, "Nikko", {36.720785,139.686834}, Prefectures::Tochigi},
  {544071821, "KarasuyamaKeisatsu", {36.652108,140.158461}, Prefectures::Tochigi},
  {543925614, "Itakura", {36.222008,139.648559}, Prefectures::Gunma},
  {543924923, "Tatebayashi", {36.245994,139.528202}, Prefectures::Gunma},
  {543933172, "Honnakanoeki", {36.258552,139.469758}, Prefectures::Gunma},
  {543933122, "Nishikoizumi", {36.25848,139.408457}, Prefectures::Gunma},
  {543933501, "Ohta", {36.294137,139.378518}, Prefectures::Gunma},
  {543942962, "Kiryu", {36.411145,139.333079}, Prefectures::Gunma},
  {543952121, "Akagi", {36.425779,139.276292}, Prefectures::Gunma},
  {543931952, "Isezaki", {36.326906,139.193895}, Prefectures::Gunma},
  {543930693, "Tamamuracho", {36.304404,139.114992}, Prefectures::Gunma},
  {543930062, "Hujioka", {36.250159,139.083324}, Prefectures::Gunma},
  {543837043, "Jyoshuhukushima", {36.2563,138.929675}, Prefectures::Gunma},
  {543837121, "Higashitomioka", {36.260842,138.901856}, Prefectures::Gunma},
  {543826522, "Shimonita", {36.210588,138.786197}, Prefectures::Gunma},
  {543930804, "Takasaki", {36.322827,139.012662}, Prefectures::Gunma},
  {543940554, "Maebashi", {36.383184,139.073217}, Prefectures::Gunma},
  {543950304, "Yoshioka", {36.447377,139.009948}, Prefectures::Gunma},
  {543950804, "Shibukawa", {36.491322,139.008798}, Prefectures::Gunma},
  {543876081, "Nakanojyo", {36.58539,138.851446}, Prefectures::Gunma},
  {543866854, "Gunmabara", {36.571722,138.824408}, Prefectures::Gunma},
  {543970722, "Numata", {36.6425,139.035623}, Prefectures::Gunma},

  {523503492, "Umeda", {34.705027,135.498427}, Prefectures::Osaka},
  {523503294, "Higobashi", {34.691661,135.496227}, Prefectures::Osaka},
  {523503284, "Nakanoshima", {34.69055,135.486616}, Prefectures::Osaka},
  {523503173, "Nishikujyou", {34.682143,135.466149}, Prefectures::Osaka},
  {523503062, "Bentencho", {34.669179,135.462577}, Prefectures::Osaka},
  {513573983, "Taisho", {34.665782,135.479248}, Prefectures::Osaka},
  {523503092, "Doutonbori", {34.668723,135.501297}, Prefectures::Osaka},
  {513574903, "Nanba", {34.664987,135.503656}, Prefectures::Osaka},
  {513574703, "Shinimamiya", {34.649793,135.501548}, Prefectures::Osaka},
  {513574713, "Tennouji", {34.648435,135.518454}, Prefectures::Osaka},
  {513574711, "Anobebashi", {34.646071,135.513477}, Prefectures::Osaka},
  {513574512, "Minamitanabe", {34.625587,135.520574}, Prefectures::Osaka},
  {513573493, "Tamaide", {34.623669,135.490285}, Prefectures::Osaka},
  {513574341, "Kireurewari", {34.609227,135.552141}, Prefectures::Osaka},
  {513574113, "Abikoeki", {34.599061,135.512784}, Prefectures::Osaka},
  {513563982, "Sakaihigashi", {34.575378,135.484796}, Prefectures::Osaka},
  {513564603, "Nakamozu", {34.556315,135.504258}, Prefectures::Osaka},
  {513564942, "KawauchiMatsubara", {34.575533,135.557137}, Prefectures::Osaka},
  {513564854, "Eganosou", {34.574946,135.573021}, Prefectures::Osaka},
  {513564874, "Hijiidera", {34.571533,135.594449}, Prefectures::Osaka},
  {513564444, "Miharaku", {34.538543,135.559896}, Prefectures::Osaka},
  {513564233, "Kitanoda", {34.523181,135.543034}, Prefectures::Osaka},
  {513554904, "Izumigaoka", {34.497191,135.511808}, Prefectures::Osaka},
  {513554942, "Kingou", {34.495268,135.559422}, Prefectures::Osaka},
  {513564083, "Tomitabayashi", {34.50452,135.601271}, Prefectures::Osaka},
  {513555803, "Kanancho", {34.491608,135.629687}, Prefectures::Osaka},
  {513554452, "Kawauchinagano", {34.451086,135.573088}, Prefectures::Osaka},
  {513563364, "Ootori", {34.531989,135.458916}, Prefectures::Osaka},
  {513563244, "Takaishi", {34.521535,135.432981}, Prefectures::Osaka},
  {513563022, "Izumiootsu", {34.50336,135.40667}, Prefectures::Osaka},
  {513553834, "Izumihutyuu", {34.48796,135.423879}, Prefectures::Osaka},
  {513553814, "Tadaoka", {34.488332,135.397436}, Prefectures::Osaka},
  {513553304, "Higashikishiwada", {34.448716,135.385171}, Prefectures::Osaka},
  {513552382, "Kaiduka", {34.445467,135.357532}, Prefectures::Osaka},
  {513542951, "Izumisano", {34.411261,135.317282}, Prefectures::Osaka},
  {513551291, "Kansaiairport", {34.432002,135.230394}, Prefectures::Osaka},
  {513542404, "Taruieki", {34.374342,135.261701}, Prefectures::Osaka},
  {513541391, "Ozakieki", {34.361544,135.240697}, Prefectures::Osaka},
  {513531812, "Hukahicho", {34.31842,135.148884}, Prefectures::Osaka},
  {513565212, "Taishicho", {34.519223,135.648978}, Prefectures::Osaka},
  {523504494, "Juudou", {34.706219,135.621383}, Prefectures::Osaka},
  {523504452, "Yokotsutsumi", {34.703467,135.572192}, Prefectures::Osaka},
  {523504124, "Morinomiya", {34.681731,135.533356}, Prefectures::Osaka},
  {513574953, "Huse", {34.664082,135.563416}, Prefectures::Osaka},
  {513574841, "Kitatatsumi", {34.652941,135.554986}, Prefectures::Osaka},
  {513574583, "Yaoeki", {34.617357,135.596782}, Prefectures::Osaka},
  {523505912, "Shinobugaoka", {34.746047,135.645545}, Prefectures::Osaka},
  {523504864, "Monma", {34.738046,135.582928}, Prefectures::Osaka},
  {523504851, "Moriguchi", {34.73518,135.56504}, Prefectures::Osaka},
  {523504433, "Noe", {34.707131,135.543387}, Prefectures::Osaka},
  {523504324, "Kyoubashi", {34.69669,135.533912}, Prefectures::Osaka},
  {523503464, "Himejima", {34.704402,135.458175}, Prefectures::Osaka},
  {523503794, "Shinoosaka", {34.733466,135.500255}, Prefectures::Osaka},
  {523503744, "Amagasaki", {34.718524,135.417286}, Prefectures::Osaka},
  {523513334, "Itami", {34.780732,135.421674}, Prefectures::Osaka},
  {523513192, "Esaka", {34.758653,135.49703}, Prefectures::Osaka},
  {523514022, "Kamisinjyo", {34.750327,135.533098}, Prefectures::Osaka},
  {523515441, "Kouno", {34.786988,135.675541}, Prefectures::Osaka},
  {523515401, "Karien", {34.784627,135.630978}, Prefectures::Osaka},
  {523514441, "Settsu", {34.78364,135.556586}, Prefectures::Osaka},
  {523514744, "Ibaraki", {34.815463,135.562399}, Prefectures::Osaka},
  {523513792, "Chisato", {34.807469,135.495255}, Prefectures::Osaka},
  {523523071, "Minoo", {34.834477,135.468419}, Prefectures::Osaka},
  {523513843, "Ikeda", {34.821589,135.425534}, Prefectures::Osaka},
  {523524291, "Takatsuki", {34.85167,135.617739}, Prefectures::Osaka},
  {523525531, "Minase", {34.877838,135.667816}, Prefectures::Osaka},

  {523502871, "Nishinomiya", {34.738958,135.348654}, Prefectures::Hyougo},
  {513447112, "Sumoto", {34.342832,134.895363}, Prefectures::Hyougo},
  {523502842, "Ashiya", {34.734243,135.30707}, Prefectures::Hyougo},
  {523502721, "HyougoSettsu", {34.726544,135.276543}, Prefectures::Hyougo},
  {523501593, "Rokkoudou", {34.714976,135.238545}, Prefectures::Hyougo},
  {523501253, "Daimaru", {34.693849,135.196045}, Prefectures::Hyougo},
  {523501132, "Shinkaichi", {34.676572,135.169034}, Prefectures::Hyougo},
  {513571814, "Shinnagata", {34.657692,135.145465}, Prefectures::Hyougo},
  {513571902, "Itashuku", {34.660017,135.133204}, Prefectures::Hyougo},
  {513570543, "Sanyoutarumizu", {34.629538,135.053661}, Prefectures::Hyougo},
  {513477793, "Akashi", {34.649036,134.992696}, Prefectures::Hyougo},
  {523406593, "Harima", {34.716644,134.868086}, Prefectures::Hyougo},
  {523416271, "Kakogawa", {34.767637,134.839365}, Prefectures::Hyougo},
  {523416442, "Takaraden", {34.784718,134.812117}, Prefectures::Hyougo},
  {523415951, "Himejie", {34.826797,134.690533}, Prefectures::Hyougo},
  {523424061, "HyougoTaishicho", {34.83327,134.593739}, Prefectures::Hyougo},
  {523414912, "Tatsuno", {34.825484,134.522363}, Prefectures::Hyougo},
  {523413661, "Nishiaise", {34.801375,134.450759}, Prefectures::Hyougo},
  {523413013, "Akaho", {34.756601,134.393266}, Prefectures::Hyougo},
  {523422383, "Kamikoori", {34.866004,134.353599}, Prefectures::Hyougo},
  {523442082, "Sayou", {35.004076,134.356878}, Prefectures::Hyougo},
  {533433461, "Hamasaka", {35.62053,134.452843}, Prefectures::Hyougo},
  {533434692, "Kasumi", {35.635605,134.622973}, Prefectures::Hyougo},
  {533426551, "Toyooka", {35.543992,134.813341}, Prefectures::Hyougo},
  {533406083, "Wadayama", {35.34117,134.851888}, Prefectures::Hyougo},
  {523447632, "Takacho", {35.050346,134.923561}, Prefectures::Hyougo},
  {523437674, "Nishiwaki", {34.971867,134.96893}, Prefectures::Hyougo},
  {523437364, "Takieki", {34.948705,134.962436}, Prefectures::Hyougo},
  {523436162, "Houjyoucho", {34.930791,134.835821}, Prefectures::Hyougo},
  {523436501, "Hukuzaki", {34.960752,134.750755}, Prefectures::Hyougo},
  {523436804, "Amachi", {34.987879,134.758851}, Prefectures::Hyougo},
  {523445793, "Teramae", {35.065462,134.743169}, Prefectures::Hyougo},
  {523444034, "Shishikuri", {35.004386,134.549438}, Prefectures::Hyougo},
  {523427142, "Ono", {34.843227,134.934328}, Prefectures::Hyougo},
  {523510304, "Shisome", {34.782473,135.007572}, Prefectures::Hyougo},
  {523501823, "Kitasuzuran", {34.739441,135.151946}, Prefectures::Hyougo},
  {523500611, "Nishikami", {34.719417,135.017416}, Prefectures::Hyougo},
  {523407933, "Inami", {34.748381,134.913248}, Prefectures::Hyougo},
  {523521683, "Mita", {34.888442,135.229983}, Prefectures::Hyougo},
  {523541643, "Shinoyamaguchi", {35.05621,135.17767}, Prefectures::Hyougo},
  {523550561, "Kashiwabara", {35.127226,135.077328}, Prefectures::Hyougo},
  
  {523505352, "Toriimae", {34.692351,135.696117}, Prefectures::Nara},
  {523506322, "YamatoNishioodera", {34.693779,135.782786}, Prefectures::Nara},
  {513575461, "Tatsutagawa", {34.617396,135.704627}, Prefectures::Osaka},
  {513575263, "Seino", {34.606015,135.700726}, Prefectures::Nara},
  {513575163, "Shinoodera", {34.597672,135.702482}, Prefectures::Nara},
  {513575081, "Samida", {34.585169,135.731091}, Prefectures::Nara},
  {513565773, "Uemaki", {34.562729,135.716671}, Prefectures::Nara},
  {513565463, "KintetsuShimoda", {34.541405,135.70413}, Prefectures::Nara},
  {513565291, "Yamatotakada", {34.519714,135.742516}, Prefectures::Nara},
  {513555884, "Yamatoshinjyo", {34.488576,135.73583}, Prefectures::Nara},
  {513555584, "KintetsuGosho", {34.46472,135.732352}, Prefectures::Nara},
  {513556334, "Tubosakayama", {34.449727,135.794925}, Prefectures::Nara},
  {513556534, "Asuka", {34.464897,135.798264}, Prefectures::Nara},
  {513546701, "Hukujin", {34.395195,135.750787}, Prefectures::Nara},
  {513545144, "Yamatohutami", {34.346037,135.684536}, Prefectures::Nara},
  {513534644, "Takanoguchi", {34.30625,135.559375}, Prefectures::Nara},
  {513567363, "Haibara", {34.529746,135.954386}, Prefectures::Nara},
  {513566174, "Sakurai", {34.51349,135.846276}, Prefectures::Nara},
  {513576163, "Tenri", {34.601151,135.830145}, Prefectures::Nara},
  {513576022, "Yuizaki", {34.584263,135.78471}, Prefectures::Nara},
  {513566631, "Nishidawara", {34.553645,135.789673}, Prefectures::Nara},
  {513566824, "Ishimi", {34.571904,135.785879}, Prefectures::Nara},
  {513566801, "Hashio", {34.570138,135.751481}, Prefectures::Nara},
  {513576204, "Ancho", {34.606445,135.756949}, Prefectures::Nara},
  {513575291, "Houryuuji", {34.601645,135.739033}, Prefectures::Nara},
  {513576421, "Tsutsui", {34.620257,135.7807}, Prefectures::Nara},
  {513575003, "Katashita", {34.588565,135.627274}, Prefectures::Nara},

  {523572601, "Ayabe", {35.302141,135.251866}, Prefectures::Kyoto},
  {523506852, "Kitsu", {34.735977,135.824927}, Prefectures::Kyoto},
  {523516131, "Iwazono", {34.759883,135.792022}, Prefectures::Kyoto},
  {523573112, "Wachi", {35.26101,135.399021}, Prefectures::Kyoto},
  {533513612, "Higashimaizuru", {35.468545,135.394886}, Prefectures::Kyoto},
  {533514832, "Wakasatakahama", {35.486407,135.547584}, Prefectures::Kyoto},
  {533514794, "Wakasahongo", {35.482623,135.619313}, Prefectures::Kyoto},
  {533516821, "Higashiohama", {35.485188,135.781118}, Prefectures::Kyoto},
  {523570594, "Hukuchiyama", {35.295979,135.118425}, Prefectures::Kyoto},
  {523546502, "Kitaouji", {35.045172,135.758704}, Prefectures::Kyoto},
  {523546304, "Imadegawa", {35.029822,135.759359}, Prefectures::Kyoto},
  {523546112, "Sanjyou", {35.009443,135.772303}, Prefectures::Kyoto},
  {523546012, "Gion", {35.003971,135.772093}, Prefectures::Kyoto},
  {523546102, "Karasumaru", {35.009992,135.759609}, Prefectures::Kyoto},
  {523545074, "Yamanouchi", {35.008304,135.72337}, Prefectures::Kyoto},
  {523536802, "Kyotoeki", {34.985849,135.758767}, Prefectures::Kyoto},
  {523536703, "Higashidera", {34.979945,135.752636}, Prefectures::Kyoto},
  {523535854, "Kamikatsura", {34.990528,135.695827}, Prefectures::Kyoto},
  {523535461, "Higashimukou", {34.953942,135.70456}, Prefectures::Kyoto},
  {523536113, "Hushimimomoyama", {34.932622,135.764301}, Prefectures::Kyoto},
  {523536232, "Rokujizou", {34.932007,135.79335}, Prefectures::Kyoto},
  {523535063, "Nagaokakyo", {34.924353,135.680006}, Prefectures::Kyoto},
  {523525741, "Yamasaki", {34.892199,135.679878}, Prefectures::Kyoto},
  {523525544, "KyotoHashimoto", {34.881949,135.684204}, Prefectures::Kyoto},
  {523525584, "Kuonyama", {34.881534,135.732697}, Prefectures::Kyoto},
  {523526212, "Terada", {34.853295,135.772111}, Prefectures::Kyoto},
  {523526282, "Ujitawara", {34.852718,135.856891}, Prefectures::Kyoto},
  {523516842, "Yamashirotaga", {34.817515,135.806251}, Prefectures::Kyoto},
  {523516812, "Nittabe", {34.820653,135.772809}, Prefectures::Kyoto},

  {513546674, "Yoshinojingu", {34.390266,135.847992}, Prefectures::Wakayama},
  {513533581, "Kasada", {34.292202,135.480245}, Prefectures::Wakayama},
  {513521753, "Wakayama", {34.23218,135.191792}, Prefectures::Wakayama},
  {513511873, "Kainan", {34.1544,135.214347}, Prefectures::Wakayama},
  {513532054, "Iwade", {34.254862,135.321072}, Prefectures::Wakayama},
  {513532193, "Uchida", {34.26529,135.364091}, Prefectures::Wakayama},
  {513522042, "Kiminocho", {34.167194,135.307575}, Prefectures::Wakayama},
  {513510092, "Minoshima", {34.085997,135.124575}, Prefectures::Wakayama},
  {513501654, "Hujinami", {34.057197,135.196615}, Prefectures::Wakayama},
  {513501343, "Yuasa", {34.031938,135.17942}, Prefectures::Wakayama},
  {503571112, "Kiiuchibara", {33.925983,135.145135}, Prefectures::Wakayama},
  {503561702, "Mihamacho", {33.893806,135.133262}, Prefectures::Wakayama},
  {503561721, "Kiigobou", {33.89432,135.154851}, Prefectures::Wakayama},
  {503551872, "Innan", {33.818423,135.219705}, Prefectures::Wakayama},
  {503552252, "Minabe", {33.767125,135.324648}, Prefectures::Wakayama},
  {503543802, "Ikitanabe", {33.733047,135.384142}, Prefectures::Wakayama},
  {503543333, "Asaki", {33.69629,135.417663}, Prefectures::Wakayama},
  {503543102, "Shirahama", {33.675803,135.387177}, Prefectures::Wakayama},
  {503523594, "Shuusanken", {33.546824,135.495525}, Prefectures::Wakayama},
  {503516722, "Kushimoto", {33.475527,135.781603}, Prefectures::Wakayama},
  {503537551, "Kiikatsuura", {33.628152,135.941418}, Prefectures::Wakayama},
  {503547694, "Shinguu", {33.725151,135.994147}, Prefectures::Wakayama},
  {503640811, "Uden", {33.737114,136.015908}, Prefectures::Wakayama},
  {503650633, "Adawa", {33.805305,136.04298}, Prefectures::Wakayama},
  {503660674, "Kumano", {33.889638,136.09886}, Prefectures::Wakayama},
  {513601853, "Owasi", {34.074725,136.190312}, Prefectures::Wakayama},
  {513611381, "Aiga", {34.111582,136.227184}, Prefectures::Wakayama},

  {533602511, "Nagahama", {35.378545,136.264941}, Prefectures::Shiga},
  {523672733, "Yonehara", {35.31477,136.289845}, Prefectures::Shiga},
  {523672213, "Hikone", {35.272213,136.263354}, Prefectures::Shiga},
  {523670502, "Konoetakashima", {35.292688,136.010133}, Prefectures::Shiga},
  {523662722, "Tagataisha", {35.226452,136.284083}, Prefectures::Shiga},
  {523661383, "Hougou", {35.197898,136.230922}, Prefectures::Shiga},
  {523661171, "Aichikawa", {35.176123,136.213369}, Prefectures::Shiga},
  {523651354, "ShigaYoukaichi", {35.114526,136.19479,}, Prefectures::Shiga},
  {523650483, "Konoeyawata", {35.122855,136.102788}, Prefectures::Shiga},
  {523640812, "Yasu", {35.068353,136.022584}, Prefectures::Shiga},
  {523547692, "Moriyama", {35.050604,135.99642}, Prefectures::Shiga},
  {523547481, "Kurihigashi", {35.037417,135.979962}, Prefectures::Shiga},
  {523547264, "Kusatsu", {35.022884,135.962202}, Prefectures::Shiga},
  {523640062, "Kouzai", {35.000612,136.082331}, Prefectures::Shiga},
  {523631631, "Mizuguchijyounan", {34.96809,136.165547}, Prefectures::Shiga},
  {523546091, "Ohtsu", {35.003051,135.864572}, Prefectures::Shiga},
  {523536853, "Yamashina", {34.992374,135.817157}, Prefectures::Shiga},

};

bool comp_id(const info_t& a, const info_t& b)
{
  return a.id < b.id;
}

int check_id(int prev_id, const info_t& info)
{
  auto curr_id = info.id;
  assert(prev_id != curr_id);
  return curr_id;
}

bool comp_place(const info_t& a, const info_t& b)
{
  return a.place < b.place;
}

std::string check_place(std::string prev_place, const info_t& info)
{
  auto curr_place = info.place;
  assert(prev_place != curr_place);
  return curr_place;
}

void check_valid()
{
  using namespace std;
  vector<info_t> tmp;
  copy(begin(data), end(data), back_inserter(tmp));
  sort(begin(tmp), end(tmp), comp_id);
  accumulate(begin(tmp), end(tmp), 0, check_id);
  sort(begin(tmp), end(tmp), comp_place);
  accumulate(begin(tmp), end(tmp), string(""), check_place);
}

enum kind_t { time_s, generation, place };

inline int pos(kind_t kind)
{
  switch (kind) {
  case time_s:
    return 350;
  case generation:
    return 480;
  case place:
  default:
    return 610;
  }
}

inline std::string dump_file(std::string base, kind_t kind)
{
  switch (kind) {
  case time_s:
    return base + ".time";
  case generation:
    return base + ".gen";
  case place:
  default:
    return base + ".place";
  }
}

inline std::string  prog(kind_t kind)
{
  switch (kind) {
  case time_s: return "tdata";
  case generation: return "gdata";
  case place:
  default:
    return "pdata";
  }
}

inline bool capture(std::string wid, const info_t& info, kind_t kind)
{
  using namespace std;
  if (kind != time_s) {
    ostringstream os;
    os << "xdotool mousemove --window " << wid << ' ';
    os << pos(kind) << ' ' << 490;
    auto x = system(os.str().c_str());
    if (x) {
      cerr << os.str() << " failed\n";
      return true;
    }
    const char* cmd = "xdotool click 1";
    auto y = system(cmd);
    if (y) {
      cerr << cmd << " failed\n";
      return true;
    }
  }
  string fn = dump_file(info.place, kind);
 label:
  ostringstream osz;
  osz << "xwd -id " << wid << " -out " << fn << " -silent";
  auto z = system(osz.str().c_str());
  if (z) {
    cerr << osz.str() << " failed\n";
    return true;
  }

  ostringstream os;
  auto c = info.coord;
  os << prog(kind) << " -in " << fn;
  os << " -x " << c.first;
  os << " -y " << c.second;
  os << " > " << fn << ".cpp";
  auto u = system(os.str().c_str());
  if (u) {
    static map<string, int> retry;
    if (retry[fn]++ > 2) {
      cerr << os.str() << " failed\n";
      return true;
    }
    sleep(5);
    goto label;
  }
  unlink(fn.c_str());
  return false;
}

inline bool close_tab(std::string wid)
{
  using namespace std;
  ostringstream os;
  os << "xdotool mousemove --window " << wid << " 210 10";
  auto x = system(os.str().c_str());
  if (x) {
    cerr << os.str() << " failed\n";
    return true;
  }
  const char* cmd = "xdotool click 1";
  auto y = system(cmd);
  if (y) {
    cerr << cmd << " failed\n";
    return true;
  }
  return false;
}

inline bool subr(const info_t& info)
{
  using namespace std;
  pid_t pid = fork();
  if (!pid) {
    ostringstream os;
    os << "https://tokyo.mobakumap.jp/#" << info.id;
    execl("/usr/bin/firefox", "firefox", os.str().c_str(), nullptr);
    cerr << "execl failed\n";
    return 1;
  }
  sleep(15);
  ostringstream os;
  os << "w."<< pid;
  string log = os.str();
  string cmd = "xwininfo -root -tree | grep 'モバイル空間統計' | awk '{print $1}'";
  cmd += "> ";
  cmd += log;
  auto y = system(cmd.c_str());
  if (y) {
    cerr << cmd << " failed\n";
    return true;
  }
  ifstream ifs(log);
  string wid;
  ifs >> wid;
  unlink(log.c_str());  
  if (wid.empty()) {
    // no firefox mobakumap page
    return true;
  }
  if (capture(wid, info, time_s))
    return true;
  if (capture(wid, info, generation))
    return true;
  if (capture(wid, info, place))
    return true;
  return close_tab(wid);
}

inline void usage(const char* prog)
{
  using namespace std;
  cerr << "usage % " << prog << " [-s Nihonbashi] [-e Shibuya] [-i]\n";
}

inline bool comp(info_t info, std::string name)
{
  return info.place == name;
}

int main(int argc, char** argv)
{
  using namespace std;
  check_valid();
  
  string s, e;
  bool ignore = false;
  for (int opt ; (opt = getopt(argc, argv, "s:e:i01")) != -1 ; ) {
    switch (opt) {
    case 's': s = optarg; break;
    case 'e': e = optarg; break;
    case 'i': ignore = true; break;
    case '0': s = "Nihonbashi"; e = "Numata"; break;
    case '1': s = "Umeda"; break;
    default: usage(argv[0]); return 1;
    }
  }

  if (optind != argc) {
    usage(argv[0]);
    return 1;
  }
    
  pid_t pid = fork();
  if (!pid) {
    ostringstream os;
    execl("/usr/bin/firefox", "firefox",
	  "https://tokyo.mobakumap.jp/", nullptr);
    cerr << "execl failed\n";
    return 1;
  }
  sleep(30);

  auto ss = begin(data);
  if (!s.empty()) {
    auto p = find_if(begin(data), end(data), bind2nd(ptr_fun(comp), s));
    if (p == end(data)) {
      cerr << '`' << s << "' not found\n";
      return 1;
    }
    ss = p;
  }
  auto ee = end(data);
  if (!e.empty()) {
    auto p = find_if(ss, end(data), bind2nd(ptr_fun(comp), e));
    if (p == end(data)) {
      cerr << '`' << e << "' not found";
      if (!s.empty())
	cerr << " after `" << s << "'";
      cerr << '\n';
      return 1;
    }
    ee = p+1;
  }

  auto p = find_if(ss, ee, subr);
  auto ret = end(data) - p;
  if (!ignore || !ret)
    return ret;
  
  for_each(p+1, ee, subr);
  return ret;
}
