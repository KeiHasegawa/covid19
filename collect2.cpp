#include <sys/wait.h>
#include <signal.h>
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
  Okinawa,
  Hokkaido,
  Aichi,
  Hukuoka,
  Miyagi,
  Shizuoka,
  Hiroshima,
  Aomori,
  Iwate,
  Akita,
  Yamagata,
  Hukushima,
  Niigata,
  Toyama,
  Ishikawa,
  Hukui,
  Yamanashi,
  Nagano,
  Gihu,
  Mie,
  Tottori,
  Shimane,
  Okayama,
  Yamaguchi,
  Saga,
  Nagasaki,
  Kumamoto,
  Kagoshima,
  Miyazaki,
  Ooita,
  Kagawa,
  Tokushima,
  Ehime,
  Kouchi,
};

std::vector<std::pair<Prefectures, std::string> > pref_str = {
  { Prefectures::Tokyo, "Tokyo"},
  { Prefectures::Kanagawa, "Kanagawa"},
  { Prefectures::Saitama, "Saitama"},
  { Prefectures::Chiba, "Chiba"},
  { Prefectures::Ibaraki, "Ibaraki"},
  { Prefectures::Tochigi, "Tochigi"},
  { Prefectures::Gunma, "Gunma"},
  { Prefectures::Osaka, "Osaka"},
  { Prefectures::Hyougo, "Hyougo"},
  { Prefectures::Nara, "Nara"},
  { Prefectures::Kyoto, "Kyoto"},
  { Prefectures::Wakayama, "Wakayama"},
  { Prefectures::Shiga, "Shiga"},
  { Prefectures::Okinawa, "Okinawa"},
  { Prefectures::Hokkaido, "Hokkaido"},
  { Prefectures::Aichi, "Aichi"},
  { Prefectures::Hukuoka, "Hukuoka"},    
  { Prefectures::Miyagi, "Miyagi"},
  { Prefectures::Shizuoka, "Shizuoka"},
  { Prefectures::Hiroshima, "Hiroshima"},
  { Prefectures::Aomori, "Aomori"},
  { Prefectures::Iwate, "Iwate"},
  { Prefectures::Akita, "Akita"},
  { Prefectures::Yamagata, "Yamagata"},
  { Prefectures::Hukushima, "Hukushima"},
  { Prefectures::Niigata, "Niigata"},
  { Prefectures::Toyama, "Toyama"},
  { Prefectures::Ishikawa, "Ishikawa"},
  { Prefectures::Hukui, "Hukui"},
  { Prefectures::Yamanashi, "Yamanashi"},
  { Prefectures::Nagano, "Nagano"},
  { Prefectures::Gihu, "Gihu"},
  { Prefectures::Mie, "Mie"},
  { Prefectures::Tottori, "Tottori"},
  { Prefectures::Shimane, "Shimane"},
  { Prefectures::Okayama, "Okayama"},
  { Prefectures::Yamaguchi, "Yamaguchi"},
  { Prefectures::Saga, "Saga"},
  { Prefectures::Nagasaki, "Nagasaki"},
  { Prefectures::Kumamoto, "Kumamoto"},
  { Prefectures::Kagoshima, "Kagoshima"},
  { Prefectures::Miyazaki, "Miyazaki"},
  { Prefectures::Ooita, "Ooita"},
  { Prefectures::Kagawa, "Kagawa"},
  { Prefectures::Tokushima, "Tokushima"},
  { Prefectures::Ehime, "Ehime"},
  { Prefectures::Kouchi, "Kouchi"},
};

std::string to_string(Prefectures x)
{
  using namespace std;
  auto it = find_if(begin(pref_str), end(pref_str),
		    [x](const pair<Prefectures, string>& p)
		    { return p.first == x; });
  assert(it != end(pref_str));
  return it->second;
}

Prefectures from_string(std::string x)
{
  using namespace std;
  auto it = find_if(begin(pref_str), end(pref_str),
		    [x](const pair<Prefectures, string>& p)
		    { return p.second == x; });
  assert(it != end(pref_str));
  return it->first;
}

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

  {392725543, "OkinawaKentyou", {26.214395,127.679337}, Prefectures::Okinawa},
  {392715932, "Toyomijyou", {26.177104,127.681291}, Prefectures::Okinawa},
  {392715433, "Itoman", {26.123542,127.665856}, Prefectures::Okinawa},
  {392715493, "Yaesecho", {26.123528,127.742226}, Prefectures::Okinawa},
  {392725283, "Nanpubara", {26.193297,127.728236}, Prefectures::Okinawa},
  {392725972, "Urazoe", {26.245875,127.721865}, Prefectures::Okinawa},
  {392716711, "Nanjyo", {26.146106,127.769519}, Prefectures::Okinawa},
  {392726303, "Yonabaracho", {26.199558,127.755468}, Prefectures::Okinawa},
  {392726604, "Saibaracho", {26.222837,127.758824}, Prefectures::Okinawa},
  {392736231, "Nakajyomura", {26.262176,127.789834}, Prefectures::Okinawa},
  {392736323, "Ginowan", {26.281497,127.778435}, Prefectures::Okinawa},
  {392736631, "Kitanakajyo", {26.301052,127.793063}, Prefectures::Okinawa},
  {392746041, "OkinawaCity", {26.334248,127.80547}, Prefectures::Okinawa},
  {392746301, "Kadenacho", {26.361372,127.755332}, Prefectures::Okinawa},
  {392746582, "Uruma", {26.378871,127.857378}, Prefectures::Okinawa},
  {392757443, "Kanatakecho", {26.456123,127.926107}, Prefectures::Okinawa},
  {392757783, "Ginoza", {26.481576,127.97558}, Prefectures::Okinawa},
  {392777181, "Nago", {26.591555,127.977475}, Prefectures::Okinawa},
  {402706544, "Iemura", {26.713491,127.807017}, Prefectures::Okinawa},
  {372512623, "Miyakojima", {24.846095,125.301883}, Prefectures::Okinawa},
  {362441023, "Ishigaki", {24.471136,124.205}, Prefectures::Okinawa},
  
  {644142594, "Gakuenmae", {43.047499,141.369021}, Prefectures::Hokkaido},
  {644142783, "Tokeidai", {43.06579,141.352372}, Prefectures::Hokkaido},
  {644142881, "YozemiSapporo", {43.069678,141.352732}, Prefectures::Hokkaido},
  {644142991, "Higashikuyakusho", {43.076165,141.363593}, Prefectures::Hokkaido},
  {644143514, "Siroishieki", {43.046343,141.395505}, Prefectures::Hokkaido},
  {644142941, "Kotonieki", {43.081541,141.307393}, Prefectures::Hokkaido},
  {644133954, "Kiyota", {42.999588,141.44385}, Prefectures::Hokkaido},
  {644143474, "ShinSapporoeki", {43.038692,141.472363}, Prefectures::Hokkaido},
  {644134753, "Kitahiroshima", {42.979328,141.563105}, Prefectures::Hokkaido},
  {644154121, "Nohoro", {43.092147,141.529351}, Prefectures::Hokkaido},
  {644145723, "Nanhorocho", {43.063734,141.650416}, Prefectures::Hokkaido},
  {644145152, "Naganumacho", {43.010334,141.695238}, Prefectures::Hokkaido},
  {644146623, "Kuriyamaeki", {43.058431,141.775886}, Prefectures::Hokkaido},
  {644146122, "Yuujineki", {43.012276,141.785916}, Prefectures::Hokkaido},
  {644126444, "Oibuneki", {42.87385,141.810805}, Prefectures::Hokkaido},
  {644124564, "Eniwa", {42.882703,141.586795}, Prefectures::Hokkaido},
  {644230802, "Minamishimizuzawa", {42.98562,142.006925}, Prefectures::Hokkaido},
  {644162053, "Ishikari", {43.171364,141.315654}, Prefectures::Hokkaido},
  {644151492, "Teina", {43.12023,141.243665}, Prefectures::Hokkaido},
  {644067393, "Otaru", {43.197698,140.993691}, Prefectures::Hokkaido},
  {644066232, "Yoichi", {43.186929,140.794593}, Prefectures::Hokkaido},
  {644075113, "Kodaira", {43.265352,140.638922}, Prefectures::Hokkaido},
  {644034702, "Iwauchi", {42.950828,140.457851}, Prefectures::Hokkaido},
  {644025892, "Guchian", {42.918032,140.770852}, Prefectures::Hokkaido},
  {644014623, "Ranetsu", {42.804538,140.528961}, Prefectures::Hokkaido},
  {644002041, "Kuromatsunai", {42.669798,140.305601}, Prefectures::Hokkaido},
  {634063103, "Oshamanbe", {42.512791,140.375103}, Prefectures::Hokkaido},
  {634050104, "Konkincho", {42.429422,140.009203}, Prefectures::Hokkaido},
  {634032012, "Yagumoeki", {42.253486,140.272988}, Prefectures::Hokkaido},
  {634014352, "Morieki", {42.10893,140.573914}, Prefectures::Hokkaido},
  {634006453, "Kabecho", {42.038376,140.816636}, Prefectures::Hokkaido},
  {624056403, "Goryoukaku", {41.789259,140.752283}, Prefectures::Hokkaido},
  {624055862, "Nanaehama", {41.817275,140.709057}, Prefectures::Hokkaido},
  {624065373, "Dainakayama", {41.864741,140.713442}, Prefectures::Hokkaido},
  {624043142, "Kikonai", {41.677713,140.43396}, Prefectures::Hokkaido},
  {624012801, "Hukushimacho", {41.483786,140.251318}, Prefectures::Hokkaido},
  {624010184, "Matsumaecho", {41.430053,140.110412}, Prefectures::Hokkaido},
  {624050692, "Uenokunicho", {41.801093,140.121346}, Prefectures::Hokkaido},
  {624061401, "Esashicho", {41.869167,140.1275}, Prefectures::Hokkaido},
  {624071083, "Atsusawabe", {41.920898,140.225472}, Prefectures::Hokkaido},
  {624071602, "Otobecho", {41.968357,140.136139}, Prefectures::Hokkaido},
  {634065973, "Toyoura", {42.579842,140.715274}, Prefectures::Hokkaido},
  {634066611, "Touyako", {42.550546,140.763622}, Prefectures::Hokkaido},
  {634056681, "Datemonbetsu", {42.469365,140.856181}, Prefectures::Hokkaido},
  {634140123, "Higashimuroran", {42.349026,141.025831}, Prefectures::Hokkaido},
  {634151441, "Noboribetsu", {42.452047,141.180894}, Prefectures::Hokkaido},
  {634162243, "Oginoeki", {42.521152,141.305988}, Prefectures::Hokkaido},
  {634174674, "Tomakomai", {42.639739,141.596789}, Prefectures::Hokkaido},
  {644107603, "Atsumacho", {42.723698,141.878022}, Prefectures::Hokkaido},
  {634167932, "Mukawaeki", {42.578817,141.923677}, Prefectures::Hokkaido},
  {634250754, "Hidakamonbetsu", {42.481211,142.072588}, Prefectures::Hokkaido},
  {634242342, "Shinkaneki", {42.360761,142.312741}, Prefectures::Hokkaido},
  {634242082, "Shizuuchi", {42.336516,142.360349}, Prefectures::Hokkaido},
  {634216833, "Higashmachieki", {42.156897,142.788593}, Prefectures::Hokkaido},
  {634217542, "Samanieki", {42.127949,142.936087}, Prefectures::Hokkaido},
  {634301114, "Erimocho", {42.016236,143.148553}, Prefectures::Hokkaido},
  {644301304, "Nakahudauchi", {42.698005,143.134159}, Prefectures::Hokkaido},
  {644315721, "Urahoro", {42.810447,143.651454}, Prefectures::Hokkaido},
  {644333063, "Ikedaeki", {42.921448,143.45325}, Prefectures::Hokkaido},
  {644322903, "Hudauchi", {42.912643,143.256177}, Prefectures::Hokkaido},
  {644331061, "Obihiro", {42.917948,143.20205}, Prefectures::Hokkaido},
  {644331952, "Otosaracho", {42.994176,143.197923}, Prefectures::Hokkaido},
  {644320932, "Memuroeki", {42.91003,143.048335}, Prefectures::Hokkaido},
  {644247103, "Tokachishimizu", {43.013738,142.879793}, Prefectures::Hokkaido},
  {644246964, "Shintoku", {43.082511,142.832569}, Prefectures::Hokkaido},
  {654203113, "Hurano", {43.347089,142.391256}, Prefectures::Hokkaido},
  {654203834, "Nakahurano", {43.405833,142.420972}, Prefectures::Hokkaido},
  {654213574, "Kamihurano", {43.463967,142.469325}, Prefectures::Hokkaido},
  {654221144, "Ashibetsu", {43.516506,142.184264}, Prefectures::Hokkaido},
  {654220634, "Akahiraeki", {43.554802,142.048524}, Prefectures::Hokkaido},
  {654127623, "Takigawaeki", {43.55517,141.901245}, Prefectures::Hokkaido},
  {654126592, "Shintotsukawa", {43.545836,141.874376}, Prefectures::Hokkaido},
  {654117922, "Sunagawa", {43.492941,141.90917}, Prefectures::Hokkaido},
  {644176984, "Miutaeki", {43.330976,141.862046}, Prefectures::Hokkaido},
  {644167901, "Mikasa", {43.245532,141.875289}, Prefectures::Hokkaido},
  {644166404, "Iwamizawa", {43.204014,141.759718}, Prefectures::Hokkaido},
  {644165712, "Shinshinotsu", {43.22531,141.649353}, Prefectures::Hokkaido},
  {644430463, "Shiranuka", {42.956195,144.076746}, Prefectures::Hokkaido},
  {644433804, "Kushiro", {42.990412,144.381878}, Prefectures::Hokkaido},
  {644446673, "Atsugisi", {43.056181,144.841165}, Prefectures::Hokkaido},
  {644550523, "Sanai", {43.129346,145.027922}, Prefectures::Hokkaido},
  {644574874, "Nemuro", {43.32368,145.597201}, Prefectures::Hokkaido},
  {654500791, "Betsukaicho", {43.393791,145.117546}, Prefectures::Hokkaido},
  {644474584, "Montyaeki", {43.298465,144.608167}, Prefectures::Hokkaido},
  {654427674, "Nakahyoutsu", {43.555221,144.971426}, Prefectures::Hokkaido},
  {654531902, "Hyoutsu", {43.661375,145.131422}, Prefectures::Hokkaido},
  {664501253, "Rausu", {44.021867,145.189673}, Prefectures::Hokkaido},
  {654465922, "Shiretokosharieki", {43.910994,144.661526}, Prefectures::Hokkaido},
  {654463264, "Koshimizu", {43.85666,144.462174}, Prefectures::Hokkaido},
  {664402212, "Katsuradai", {44.017034,144.273315}, Prefectures::Hokkaido},
  {654461934, "Omanbetsu", {43.91606,144.171346}, Prefectures::Hokkaido},
  {654460081, "Mihoro", {43.836597,144.106304}, Prefectures::Hokkaido},
  {654357614, "HokkaidoKitami", {43.804867,143.89722}, Prefectures::Hokkaido},
  {654440414, "Tsubetsu", {43.706356,144.025018}, Prefectures::Hokkaido},
  {654345791, "Kunshihucho", {43.725349,143.741719}, Prefectures::Hokkaido},
  {664306212, "Saromacho", {44.017858,143.774644}, Prefectures::Hokkaido},
  {664304712, "Enkei", {44.059921,143.520633}, Prefectures::Hokkaido},
  {664342283, "Monbetsu", {44.356353,143.354406}, Prefectures::Hokkaido},
  {664235602, "Shimokawacho", {44.302631,142.63541}, Prefectures::Hokkaido},
  {664243173, "Nayori", {44.349383,142.465274}, Prefectures::Hokkaido},
  {664223013, "Shibetsu", {44.17254,142.388257}, Prefectures::Hokkaido},
  {664203331, "Wakan", {44.027174,142.415321}, Prefectures::Hokkaido},
  {654262181, "Takasucho", {43.843388,142.354501}, Prefectures::Hokkaido},
  {654254911, "Touma", {43.825452,142.516769}, Prefectures::Hokkaido},
  {654252184, "Asahikawa", {43.762762,142.358511}, Prefectures::Hokkaido},
  {654243363, "Higashishinraku", {43.696632,142.451467}, Prefectures::Hokkaido},
  {654233064, "Biei", {43.59114,142.46175}, Prefectures::Hokkaido},
  {664267964, "Otakecho", {44.582563,142.962028}, Prefectures::Hokkaido},
  {664252783, "Mishincho", {44.482965,142.35039}, Prefectures::Hokkaido},
  {674234264, "Shisachicho", {44.938695,142.581442}, Prefectures::Hokkaido},
  {674125694, "Tenshiocho", {44.888285,141.745144}, Prefectures::Hokkaido},
  {674156214, "Houhu", {45.104569,141.772491}, Prefectures::Hokkaido},
  {674270984, "Sarubarai", {45.33065,142.109133}, Prefectures::Hokkaido},
  {684105744, "Wakkanai", {45.398145,141.683072}, Prefectures::Hokkaido},

  {523667004, "Nagoyaeki", {35.170915,136.881537}, Prefectures::Aichi},
  {523667022, "Sakaecho", {35.170529,136.908809}, Prefectures::Aichi},
  {523667024, "Kuyaoodouri", {35.173741,136.907777}, Prefectures::Aichi},
  {523657902, "Sasasima", {35.161868,136.881793}, Prefectures::Aichi},
  {523667311, "Jyoushin", {35.192207,136.890837}, Prefectures::Aichi},
  {523666382, "Hutatsuiri", {35.194692,136.859229}, Prefectures::Aichi},
  {523666363, "Jinmokudera", {35.195969,136.825482}, Prefectures::Aichi},
  {523666152, "Daichicho", {35.175095,136.8201}, Prefectures::Aichi},
  {523656534, "Kintetsukanie", {35.129734,136.794151}, Prefectures::Aichi},
  {523655383, "Kintetsuyatomi", {35.113605,136.727575}, Prefectures::Aichi},
  {523646931, "Asukamura", {35.078861,136.791252}, Prefectures::Aichi},
  {523647211, "Ohtagawa", {35.020489,136.892837}, Prefectures::Aichi},
  {523636991, "Asakura", {34.99361,136.863111}, Prefectures::Aichi},
  {523647461, "Kyouwa", {35.035379,136.954532}, Prefectures::Aichi},
  {523637774, "Ogawaeki", {34.981247,136.971893}, Prefectures::Aichi},
  {523637193, "Mikawatakahama", {34.930513,136.990046}, Prefectures::Aichi},
  {523627691, "Aominami", {34.887203,136.989655}, Prefectures::Aichi},
  {523720344, "Nishio", {34.863822,137.057908}, Prefectures::Aichi},
  {523721331, "Kouda", {34.859944,137.164655}, Prefectures::Aichi},
  {523711883, "Gamagouri", {34.82292,137.226053}, Prefectures::Aichi},
  {523722061, "Kokuhu", {34.837608,137.328123}, Prefectures::Aichi},
  {523713104, "Ekimaeoodouri", {34.763115,137.385865}, Prefectures::Aichi},
  {523702012, "Mikawatawara", {34.666866,137.268739}, Prefectures::Aichi},
  {523723891, "Shinshiro", {34.90113,137.493018}, Prefectures::Aichi},
  {523741623, "Toyota", {35.055469,137.150706}, Prefectures::Aichi},
  {523750582, "Miyoshigaoka", {35.126928,137.111098}, Prefectures::Aichi},
  {523760034, "Nagakude", {35.171534,137.049736}, Prefectures::Aichi},
  {523760674, "Owariseto", {35.225197,137.097309}, Prefectures::Aichi},
  {523770133, "Takakuradera", {35.264438,137.043071}, Prefectures::Aichi},
  {523760622, "Owariasahi", {35.216888,137.03599}, Prefectures::Aichi},
  {523677343, "Komakiguchi", {35.281767,136.927636}, Prefectures::Aichi},
  {533607554, "Inuyama", {35.38032,136.945692}, Prefectures::Aichi},
  {533607331, "Hukuwa", {35.359675,136.916051}, Prefectures::Aichi},
  {533607121, "Kashimori", {35.344872,136.90045}, Prefectures::Aichi},
  {533606092, "Enan", {35.335113,136.872086}, Prefectures::Aichi},
  {523676632, "Owariichinomiya", {35.30218,136.797338}, Prefectures::Aichi},
  {523665181, "Tsushima", {35.177619,136.730825}, Prefectures::Aichi},
  {523655983, "Hibino", {35.163637,136.728547}, Prefectures::Aichi},
  {523657422, "Denmacho", {35.120775,136.910384}, Prefectures::Aichi},
  {523657324, "Toyotahoncho", {35.113647,136.910783}, Prefectures::Aichi},
  {523657204, "Minatokuyakusho", {35.106081,136.884808}, Prefectures::Aichi},

  {503033034, "Hakata", {33.589728,130.420727}, Prefectures::Hukuoka},
  {503033014, "Tenjin", {33.588689,130.399966}, Prefectures::Hukuoka},
  {503023831, "Takamiya", {33.56699,130.41477}, Prefectures::Hukuoka},
  {503032082, "Nishishineki", {33.583521,130.359206}, Prefectures::Hukuoka},
  {503022584, "Hukudaimae", {33.547478,130.36222}, Prefectures::Hukuoka},
  {503032061, "Meihama", {33.583748,130.325073}, Prefectures::Hukuoka},
  {503021654, "Chikuzenmaehara", {33.557077,130.199326}, Prefectures::Hukuoka},
  {503131234, "Yoshitomi", {33.604845,131.173822}, Prefectures::Hukuoka},
  {503131403, "Ushimaeki", {33.621218,131.126315}, Prefectures::Hukuoka},
  {503140033, "Chikujyoueki", {33.673149,131.03773}, Prefectures::Hukuoka},
  {503047772, "Yukihashi", {33.728814,130.970099}, Prefectures::Hukuoka},
  {503037851, "Saigawa", {33.650516,130.939303}, Prefectures::Hukuoka},
  {503057072, "Konamisenishikoudai", {33.752989,130.971985}, Prefectures::Hukuoka},
  {503067101, "Keibajyoumae", {33.842926,130.87655}, Prefectures::Hukuoka},
  {503077373, "Idemitsubijutsukan", {33.886968,130.882576}, Prefectures::Hukuoka},
  {503067602, "Oguraeki", {33.947606,130.965246}, Prefectures::Hukuoka},
  {503066754, "Tohataeki", {33.897208,130.82164}, Prefectures::Hukuoka},
  {503066722, "Hijinoki", {33.893374,130.781894}, Prefectures::Hukuoka},
  {503066432, "Yawataeki", {33.869238,130.795365}, Prefectures::Hukuoka},
  {503066313, "Kurosakieki", {33.866787,130.766278}, Prefectures::Hukuoka},
  {503055883, "Tsuuyaeki", {33.822631,130.726123}, Prefectures::Hukuoka},
  {503065731, "Ashiyacho", {33.893854,130.663884}, Prefectures::Hukuoka},
  {503065252, "Mizumakieki", {33.852349,130.695375}, Prefectures::Hukuoka},
  {503055081, "Chikuhoutyokuhou", {33.753389,130.726069}, Prefectures::Hukuoka},
  {503064094, "Ebitsu", {33.840127,130.623882}, Prefectures::Hukuoka},
  {503045633, "Wakamiya", {33.723867,130.667488}, Prefectures::Hukuoka},
  {503054654, "Akama", {33.80813,130.569887}, Prefectures::Hukuoka},
  {503053184, "Hukuma", {33.763596,130.487004}, Prefectures::Hukuoka},
  {503043773, "Kogaeki", {33.732335,130.466642}, Prefectures::Hukuoka},
  {503043552, "Shinguchuoh", {33.711777,130.449262}, Prefectures::Hukuoka},
  {503043353, "Hukukoudaimae", {33.698445,130.440624}, Prefectures::Hukuoka},
  {503034703, "Hisayamacho", {33.646728,130.499881}, Prefectures::Hukuoka},
  {503034414, "Shinokurieki", {33.623916,130.524816}, Prefectures::Hukuoka},
  {503033354, "Yuzusu", {33.613316,130.444654}, Prefectures::Hukuoka},
  {503033083, "Shimencho", {33.591404,130.47973}, Prefectures::Hukuoka},
  {503034001, "Sukeityuoh", {33.586959,130.505094}, Prefectures::Hukuoka},
  {503024811, "Umieki", {33.569142,130.513276}, Prefectures::Hukuoka},
  {503024221, "Dazaihu", {33.519042,130.531392}, Prefectures::Hukuoka},
  {503023472, "Kasugaeki", {33.535362,130.468545}, Prefectures::Hukuoka},
  {503023474, "Kasugaharaeki", {33.537964,130.473126}, Prefectures::Hukuoka},
  {503023242, "Hakataminami", {33.517855,130.436852}, Prefectures::Hukuoka},
  {503014723, "Tenpaisan", {33.482291,130.529984}, Prefectures::Hukuoka},
  {503026882, "Soeda", {33.567274,130.85659}, Prefectures::Hukuoka},
  {503006003, "Chikugoyoshii", {33.340909,130.753134}, Prefectures::Hukuoka},
  {503015021, "Amaki", {33.419218,130.653588}, Prefectures::Hukuoka},
  {503004994, "Tachiarai", {33.413898,130.618894}, Prefectures::Hukuoka},
  {503004743, "Nishitetsukogouri", {33.396121,130.553567}, Prefectures::Hukuoka},
  {503004872, "Imaguma", {33.403821,130.593985}, Prefectures::Hukuoka},
  {493043353, "Ohmuta", {33.029659,130.44409}, Prefectures::Hukuoka},
  {493063404, "Ookawa", {33.206618,130.384004}, Prefectures::Hukuoka},
  {493074712, "Kurume", {33.312436,130.521461}, Prefectures::Hukuoka},  
  
  {584124744, "Kesennuma", {38.89852,141.562502}, Prefectures::Miyagi},
  {574037101, "Aobadoori", {38.260683,140.878116}, Prefectures::Miyagi},
  {574037102, "Sendaieki", {38.260132,140.882437}, Prefectures::Miyagi},
  {574037004, "Miyaginodoori", {38.258472,140.885965}, Prefectures::Miyagi},
  {574027603, "Nagamachiminami", {38.22462,140.87656}, Prefectures::Miyagi},
  {574017914, "Morisekinoshita", {38.165349,140.896144}, Prefectures::Miyagi},
  {574016391, "Iwanuma", {38.111908,140.864159}, Prefectures::Miyagi},
  {574006484, "Watarieki", {38.039891,140.861264}, Prefectures::Miyagi},
  {574015472, "Muratacho", {38.118539,140.722405}, Prefectures::Miyagi},
  {574025111, "Kawasakicho", {38.177756,140.64316}, Prefectures::Miyagi},
  {574006711, "Hunaokaeki", {38.05928,140.768335}, Prefectures::Miyagi},
  {564076714, "Kakutaeki", {37.979284,140.772442}, Prefectures::Miyagi},
  {574005001, "Shiroishi", {38.00359,140.626246}, Prefectures::Miyagi},
  {574005593, "Oogawara", {38.047775,140.740608}, Prefectures::Miyagi},
  {574130501, "Tagajyo", {38.291807,141.005809}, Prefectures::Miyagi},
  {574130711, "Shiogama", {38.311919,141.018321}, Prefectures::Miyagi},
  {574037984, "Rihu", {38.329472,140.98474}, Prefectures::Miyagi},
  {574037803, "Izumi", {38.323359,140.880805}, Prefectures::Miyagi},
  {574140554, "Matsushima", {38.382774,141.073535}, Prefectures::Miyagi},
  {574150003, "Oosatocho", {38.424289,141.004491}, Prefectures::Miyagi},
  {574151193, "Rikuzenakai", {38.432523,141.238991}, Prefectures::Miyagi},
  {574057202, "Taiwacho", {38.437381,140.886333}, Prefectures::Miyagi},
  {574152241, "Ishinomaki", {38.435358,141.303485}, Prefectures::Miyagi},
  {574160453, "Oushida", {38.541502,141.063707}, Prefectures::Miyagi},
  {574067873, "Hurukawa", {38.57061,140.96773}, Prefectures::Miyagi},
  {574066583, "Shikimacho", {38.548929,140.849908}, Prefectures::Miyagi},
  {574066883, "Kamicho", {38.571763,140.854793}, Prefectures::Miyagi},

  {523950261, "Atami", {35.103842,139.077884}, Prefectures::Shizuoka},
  {523930771, "Ito", {34.97461,139.092218}, Prefectures::Shizuoka},
  {523910224, "Izu", {34.774544,139.037391}, Prefectures::Shizuoka},
  {523807994, "Kawazu", {34.747407,138.995923}, Prefectures::Shizuoka},
  {523807154, "Shimoda", {34.67912,138.944444}, Prefectures::Shizuoka},
  {523816021, "Matsuzakicho", {34.752722,138.778838}, Prefectures::Shizuoka},
  {523816223, "Nishiizu", {34.771693,138.775334}, Prefectures::Shizuoka},
  {523837763, "Shuuzenji", {34.979241,138.950974}, Prefectures::Shizuoka},
  {523847454, "Izunagaoka", {35.039818,138.9475}, Prefectures::Shizuoka},
  {523847951, "Izunita", {35.079111,138.941606}, Prefectures::Shizuoka},
  {523857123, "Shimizucho", {35.099033,138.902749}, Prefectures::Shizuoka},
  {523857422, "Mishima", {35.119335,138.911166}, Prefectures::Shizuoka},
  {523857512, "Shimodokari", {35.129525,138.895277}, Prefectures::Shizuoka},
  {523867024, "Susono", {35.171742,138.909466}, Prefectures::Shizuoka},
  {523877544, "Gotenba", {35.300123,138.934056}, Prefectures::Shizuoka},
  {533807392, "Surugakoyama", {35.358706,138.998844}, Prefectures::Shizuoka},
  {523856282, "Numazu", {35.102649,138.859801}, Prefectures::Shizuoka},
  {523855813, "Yuzukieki", {35.157333,138.639207}, Prefectures::Shizuoka},
  {523864693, "Hujinomiya", {35.221205,138.615215}, Prefectures::Shizuoka},
  {523843051, "Kusanagi", {35.002586,138.441433}, Prefectures::Shizuoka},
  {523833724, "Higashishizuoka", {34.984763,138.413538}, Prefectures::Shizuoka},
  {523833613, "Shizuokaeki", {34.972187,138.3889}, Prefectures::Shizuoka},
  {523822453, "Yaizu", {34.872459,138.318504}, Prefectures::Shizuoka},
  {523822103, "Hujieda", {34.849182,138.252038}, Prefectures::Shizuoka},
  {523812201, "Yoshidacho", {34.770963,138.252077}, Prefectures::Shizuoka},
  {523801874, "Makinohara", {34.740001,138.224625}, Prefectures::Shizuoka},
  {523811934, "Shimada", {34.830155,138.173407}, Prefectures::Shizuoka},
  {513871603, "Omaezaki", {34.637974,138.128162}, Prefectures::Shizuoka},
  {523810162, "Kikukawa", {34.761665,138.085343}, Prefectures::Shizuoka},
  {523810201, "Kakegawa", {34.77039,137.999797}, Prefectures::Shizuoka},
  {523717062, "Ainoeki", {34.752465,137.961651}, Prefectures::Shizuoka},
  {523717943, "Tomen", {34.83139,137.930775}, Prefectures::Shizuoka},
  {523706581, "Iwata", {34.710188,137.852327}, Prefectures::Shizuoka},
  {523726351, "Hutamatahoncho", {34.859614,137.812714}, Prefectures::Shizuoka},
  {523716421, "Enshukomatsu", {34.784639,137.778099}, Prefectures::Shizuoka},
  {523706903, "Jidoushagakkoumae", {34.747681,137.751862}, Prefectures::Shizuoka},
  {523705484, "Daiichidoori", {34.707268,137.732676}, Prefectures::Shizuoka},
  {523705244, "Takatsuka", {34.690575,137.681954}, Prefectures::Shizuoka},
  {523714193, "Kansanji", {34.763764,137.61731}, Prefectures::Shizuoka},
  {523714464, "Higashitsuzuki", {34.790238,137.586723}, Prefectures::Shizuoka},
  {523704632, "Washizu", {34.716707,137.546326}, Prefectures::Shizuoka},

  {513352884, "Hukuyama", {34.488944,133.362542}, Prefectures::Hiroshima},
  {513362703, "Takagi", {34.562959,133.253346}, Prefectures::Hiroshima},
  {523320311, "Bigoshouhara", {34.862336,133.016474}, Prefectures::Hiroshima},
  {513341853, "Onomichi", {34.404865,133.193159}, Prefectures::Hiroshima},
  {513331063, "Ueshimacho", {34.257467,133.204492}, Prefectures::Hiroshima},
  {513340862, "Miharaeki", {34.400708,133.083197}, Prefectures::Hiroshima},
  {523216681, "Mitsugi", {34.802645,132.856152}, Prefectures::Hiroshima},
  {513275374, "Mukoubara", {34.615053,132.720031}, Prefectures::Hiroshima},
  {513255194, "Saijyoueki", {34.431407,132.743896}, Prefectures::Hiroshima},
  {513247024, "Takeharaeki", {34.339477,132.910661}, Prefectures::Hiroshima},
  {513244062, "Kumanocho", {34.335791,132.584506}, Prefectures::Hiroshima},
  {513224942, "Kure", {34.244647,132.557585}, Prefectures::Hiroshima},
  {513244222, "Yanoeki", {34.352111,132.531952}, Prefectures::Hiroshima},
  {513244424, "Kaidacho", {34.372264,132.53609}, Prefectures::Hiroshima},
  {513244004, "Sakaeki", {34.338752,132.510788}, Prefectures::Hiroshima},
  {513244501, "Kouyoueki", {34.376325,132.506446}, Prefectures::Hiroshima},
  {513254704, "Kumuraeki", {34.482091,132.508082}, Prefectures::Hiroshima},
  {513243783, "Hiroshimaeki", {34.397667,132.475379}, Prefectures::Hiroshima},
  {513243772, "Inaricho", {34.392666,132.47123}, Prefectures::Hiroshima},
  {513243762, "Kamiyacho", {34.3955,132.456854}, Prefectures::Hiroshima},
  {513243961, "Yokogawaeki", {34.40996,132.450602}, Prefectures::Hiroshima},
  {513253372, "Saibaraeki", {34.443331,132.474793}, Prefectures::Hiroshima},
  {523204033, "Kitahiroshimacho", {34.674644,132.538386}, Prefectures::Hiroshima},
  {513242383, "Rakurakuen", {34.364296,132.351961}, Prefectures::Hiroshima},
  {513242152, "JAHiroshima", {34.343936,132.322436}, Prefectures::Hiroshima},
  {513261981, "Akiootacho", {34.576781,132.227171}, Prefectures::Hiroshima},
  {513221672, "Ootake", {34.217754,132.223365}, Prefectures::Hiroshima},

  {614171353, "Simokitaeki", {41.282743,141.189904}, Prefectures::Aomori},
  {614151092, "Mutsuyokohama", {41.086601,141.249659}, Prefectures::Aomori},
  {614132692, "Rokkasho", {40.967402,141.374211}, Prefectures::Aomori},
  {614120294, "Noheji", {40.85518,141.119545}, Prefectures::Aomori},
  {614015984, "Aomorieki", {40.828675,140.734745}, Prefectures::Aomori},
  {614102081, "Misawa", {40.669446,141.353717}, Prefectures::Aomori},
  {604171363, "Towada", {40.612571,141.205468}, Prefectures::Aomori},
  {604163193, "Hachinohe", {40.516288,141.488974}, Prefectures::Aomori},
  {604141023, "Tagocho", {40.340033,141.152283}, Prefectures::Aomori},
  {614013752, "Goshogawara", {40.808915,140.447774}, Prefectures::Aomori},
  {614011372, "Ajigasawa", {40.775218,140.220741}, Prefectures::Aomori},
  {614013044, "Tsuruta", {40.757977,140.435356}, Prefectures::Aomori},
  {614003364, "Itayanagi", {40.697207,140.461723}, Prefectures::Aomori},
  {604074773, "Kuroishi", {40.648188,140.59183}, Prefectures::Aomori},
  {604074714, "Kawabecho", {40.646628,140.52091}, Prefectures::Aomori},
  {604074801, "Hujisaki", {40.653574,140.500028}, Prefectures::Aomori},
  {604073184, "Hirosaki", {40.599151,140.48522}, Prefectures::Aomori},
  {604074042, "Hiraka", {40.584973,140.561026}, Prefectures::Aomori},
  {604064253, "Oowani", {40.521981,140.566695}, Prefectures::Aomori},

  {604145971, "Taneichi", {40.410363,141.715099}, Prefectures::Iwate},
  {604132431, "Tome", {40.285586,141.290782}, Prefectures::Iwate},
  {604126214, "Kuji", {40.190585,141.770773}, Prefectures::Iwate},
  {594171571, "Iwatemiyauchi", {39.960917,141.217574}, Prefectures::Iwate},
  {594160983, "Oozara", {39.913756,141.100825}, Prefectures::Iwate},
  {594151514, "Takisawa", {39.798806,141.149737}, Prefectures::Iwate},
  {594141402, "Morioka", {39.701437,141.136723}, Prefectures::Iwate},
  {594047274, "Shizukuishi", {39.689203,140.974947}, Prefectures::Iwate},
  {594131314, "Yahaba", {39.613189,141.148107}, Prefectures::Iwate},
  {594121624, "Shiba", {39.554835,141.159859}, Prefectures::Iwate},
  {594137654, "Miyakoeki", {39.640271,141.94658}, Prefectures::Iwate},
  {594100782, "Hanamaki", {39.393164,141.110713}, Prefectures::Iwate},
  {584174923, "Toono", {39.332455,141.530755}, Prefectures::Iwate},
  {594117174, "Iwatehunakosi", {39.43118,141.974017}, Prefectures::Iwate},
  {594107451, "Kirikiri", {39.369714,141.938884}, Prefectures::Iwate},
  {584176294, "Kamaishi", {39.272941,141.872798}, Prefectures::Iwate},
  {584170394, "Kitakami", {39.282201,141.122612}, Prefectures::Iwate},
  {584076723, "Hottoyuda", {39.314649,140.776066}, Prefectures::Iwate},
  {584160393, "Kanegasaki", {39.199875,141.112714}, Prefectures::Iwate},
  {584151614, "Mizusawa", {39.138941,141.146238}, Prefectures::Iwate},
  {584130893, "Hiraizumi", {38.988122,141.11778}, Prefectures::Iwate},
  {584131111, "Ichinoseki", {38.926292,141.137575}, Prefectures::Iwate},
  {584155062, "Oohunato", {39.085517,141.710807}, Prefectures::Iwate},

  {604034143, "Oodate", {40.266672,140.554575}, Prefectures::Akita},
  {604022794, "Takanosu", {40.232064,140.369089}, Prefectures::Akita},
  {604026224, "Hanawa", {40.189509,140.785771}, Prefectures::Akita},
  {604020424, "Noshiro", {40.206307,140.033065}, Prefectures::Akita},
  {594070363, "Hachirougata", {39.947839,140.078463}, Prefectures::Akita},
  {594070382, "Gojyoumoku", {39.943897,140.111309}, Prefectures::Akita},
  {594060961, "Igawasakura", {39.911982,140.075993}, Prefectures::Akita},
  {594060453, "Ookuboeki", {39.870904,140.062996}, Prefectures::Akita},
  {593966672, "Oga", {39.883618,139.848292}, Prefectures::Akita},
  {594041601, "Akitaeki", {39.716884,140.129853}, Prefectures::Akita},
  {594034152, "Kakudate", {39.591716,140.571064}, Prefectures::Akita},
  {594013583, "Oomagari", {39.465628,140.479806}, Prefectures::Akita},
  {594000642, "Nanegohonjyou", {39.386609,140.057298}, Prefectures::Akita},
  {583977473, "Nikaho", {39.289847,139.963931}, Prefectures::Akita},
  {584074742, "Yokote", {39.31029,140.560646}, Prefectures::Akita},
  {584053984, "Yuzawa", {39.163777,140.486993}, Prefectures::Akita},

  {583947123, "Yuusa", {39.015999,139.905427}, Prefectures::Yamagata},
  {583936074, "Sakata", {38.922231,139.845895}, Prefectures::Yamagata},
  {583927122, "Yomoku", {38.844242,139.911448}, Prefectures::Yamagata},
  {584022203, "Mamurogawa", {38.858278,140.254834}, Prefectures::Yamagata},
  {584012143, "Shinjyo", {38.762011,140.306147}, Prefectures::Yamagata},
  {584014013, "Mogami", {38.755881,140.517594}, Prefectures::Yamagata},
  {583906864, "Tsuruoka", {38.740141,139.835488}, Prefectures::Yamagata},
  {574073101, "Ooishida", {38.595784,140.375336}, Prefectures::Yamagata},
  {574053702, "Murayama", {38.477076,140.386396}, Prefectures::Yamagata},
  {574053101, "Sakuranbohigashine", {38.428415,140.380816}, Prefectures::Yamagata},
  {574052151, "Kahokucho", {38.426307,140.314309}, Prefectures::Yamagata},
  {574041564, "Hidarisawa", {38.382165,140.208055}, Prefectures::Yamagata},
  {574042414, "Sagae", {38.372057,140.274633}, Prefectures::Yamagata},
  {574042191, "Tendou", {38.341621,140.365648}, Prefectures::Yamagata},
  {574032914, "Hanemaenagasaki", {38.333589,140.273324}, Prefectures::Yamagata},
  {574032512, "Hanemaeyamabe", {38.294566,140.271554}, Prefectures::Yamagata},
  {574022963, "Yamagataeki", {38.248926,140.327303}, Prefectures::Yamagata},
  {574012821, "Kaminoyama", {38.152194,140.278615}, Prefectures::Yamagata},
  {574010324, "Ayamekouen", {38.114303,140.032666}, Prefectures::Yamagata},
  {574001802, "Miyauchieki", {38.070866,140.135354}, Prefectures::Yamagata},
  {574000034, "Hanemaekomatsu", {38.00476,140.048531}, Prefectures::Yamagata},
  {564061901, "Yonezawa", {37.909638,140.128107}, Prefectures::Yamagata},
  
  {564064531, "Hujitaeki", {37.8789,140.539466}, Prefectures::Hukushima},
  {564064213, "Kuwaori", {37.855228,140.517555}, Prefectures::Hukushima},
  {564054744, "Hohara", {37.814735,140.556271}, Prefectures::Hukushima},
  {564053064, "Hukushimaeki", {37.754212,140.459216}, Prefectures::Hukushima},
  {564057641, "Souma", {37.802531,140.925714}, Prefectures::Hukushima},
  {564037674, "Haranomachi", {37.638134,140.970968}, Prefectures::Hukushima},
  {564034974, "Kawamatacho", {37.664994,140.598313}, Prefectures::Hukushima},
  {564033044, "Nihonmatsu", {37.589603,140.435427}, Prefectures::Hukushima},
  {564022492, "Ootamamura", {37.534388,140.371189}, Prefectures::Hukushima},
  {564023114, "Motomiya", {37.514146,140.399542}, Prefectures::Hukushima},
  {564020583, "Inawashiro", {37.546452,140.103088}, Prefectures::Hukushima},
  {563917831, "Nishiwakamatsu", {37.485955,139.914094}, Prefectures::Hukushima},
  {563926654, "Aizusakashita", {37.55675,139.821515}, Prefectures::Hukushima},
  {563916671, "Aizutakada", {37.470899,139.841323}, Prefectures::Hukushima},
  {564003713, "Kooriyama", {37.398196,140.388129}, Prefectures::Hukushima},
  {554072692, "Sukagawa", {37.300306,140.372098}, Prefectures::Hukushima},
  {554075302, "Onoshinmachi", {37.275204,140.636783}, Prefectures::Hukushima},
  {554067592, "Hirono", {37.211628,140.998652}, Prefectures::Hukushima},
  {554053654, "Banjyouishikawa", {37.140759,140.44398}, Prefectures::Hukushima},
  {554043933, "Banjyouasakawa", {37.079849,140.414402}, Prefectures::Hukushima},
  {554043213, "Tyuuhou", {37.022494,140.393267}, Prefectures::Hukushima},
  {554033522, "Banjyouhanawa", {36.958696,140.412046}, Prefectures::Hukushima},
  {554051453, "Shinsirakawa", {37.122914,140.188107}, Prefectures::Hukushima},
  {554051573, "Shirakawa", {37.130199,140.21275}, Prefectures::Hukushima},
  {554052834, "Izumisaki", {37.158087,140.298972}, Prefectures::Hukushima},
  {554062463, "Yabuki", {37.205325,140.328165}, Prefectures::Hukushima},
  {554072072, "Kagamiishi", {37.250605,140.346789}, Prefectures::Hukushima},
  {554047613, "Iwaki", {37.058216,140.892236}, Prefectures::Hukushima},

  {573923671, "Murakami", {38.220318,139.463574}, Prefectures::Niigata},
  {563972362, "Shinhotta", {37.944053,139.335096}, Prefectures::Niigata},
  {563971071, "Houei", {37.920108,139.215913}, Prefectures::Niigata},
  {563960942, "Niigataeki", {37.912039,139.061775}, Prefectures::Niigata},
  {563960774, "Echigoishiyama", {37.896357,139.095397}, Prefectures::Niigata},
  {563960703, "Aoyamaeki", {37.898759,139.001779}, Prefectures::Niigata},
  {563960582, "Kameda", {37.877391,139.108173}, Prefectures::Niigata},
  {563961071, "Mizuhara", {37.83648,139.21725}, Prefectures::Niigata},
  {563950692, "Niizu", {37.800452,139.121149}, Prefectures::Niigata},
  {563941841, "Goizumi", {37.734406,139.179786}, Prefectures::Niigata},
  {563950114, "Minamikuyakusho", {37.765826,139.019133}, Prefectures::Niigata},
  {563857013, "Maki", {37.756701,138.889477}, Prefectures::Niigata},
  {563940342, "Hanyuuda", {37.693473,139.060738}, Prefectures::Niigata},
  {563930932, "Kamo", {37.658883,139.049023}, Prefectures::Niigata},
  {563837572, "Higashisanjyou", {37.62841,138.974305}, Prefectures::Niigata},
  {563847201, "Yoshidaeki", {37.687125,138.878675}, Prefectures::Niigata},
  {563825373, "Izumosaki", {37.531928,138.716222}, Prefectures::Niigata},
  {563827423, "Mitsukeeki", {37.540171,138.904735}, Prefectures::Niigata},
  {563816383, "Nagaoka", {37.448014,138.854047}, Prefectures::Niigata},
  {563804453, "Kashiwazaki", {37.372959,138.565466}, Prefectures::Niigata},
  {553876751, "Kochitani", {37.309639,138.81353}, Prefectures::Niigata},
  {553867843, "Echigohorinouchi", {37.238928,138.928218}, Prefectures::Niigata},
  {553856601, "Tookamachi", {37.1349,138.75671}, Prefectures::Niigata},
  {553851393, "Takadaeki", {37.115157,138.242226}, Prefectures::Niigata},
  {553846474, "Shiosawa", {37.041398,138.848529}, Prefectures::Niigata},
  {553842301, "Araieki", {37.02674,138.255591}, Prefectures::Niigata},
  {553746582, "Itoigawa", {37.043542,137.861613}, Prefectures::Niigata},
  {573802291, "Sado", {38.067872,138.389126}, Prefectures::Niigata},

  {553734441, "Tomarieki", {36.951953,137.555961}, Prefectures::Toyama},
  {553733294, "Iriyoshi", {36.94139,137.499484}, Prefectures::Toyama},
  {553723454, "Kurobe", {36.873946,137.444367}, Prefectures::Toyama},
  {553713723, "Uotsu", {36.815242,137.400481}, Prefectures::Toyama},
  {553712272, "Namekawa", {36.769384,137.348611}, Prefectures::Toyama},
  {553702484, "Kamiichi", {36.704422,137.357708}, Prefectures::Toyama},
  {543772953, "Ghyakugoku", {36.665341,137.3143}, Prefectures::Toyama},
  {553701471, "Toyamaeki", {36.700806,137.214002}, Prefectures::Toyama},
  {553700671, "ToyamaKosugi", {36.720745,137.09265}, Prefectures::Toyama},
  {553700911, "ToyamaSuehirocho", {36.743813,137.012622}, Prefectures::Toyama},
  {553606093, "Ishidoueki", {36.672439,136.865561}, Prefectures::Toyama},
  {553627193, "Himieki", {36.849492,136.990693}, Prefectures::Toyama},
  {543677661, "Tonami", {36.636555,136.953693}, Prefectures::Toyama},
  {543677034, "Hukuno", {36.58855,136.923185}, Prefectures::Toyama},

  {563607614, "Wajima", {37.390552,136.899096}, Prefectures::Ishikawa},
  {553771614, "Notocho", {37.310334,137.147694}, Prefectures::Ishikawa},
  {553667721, "Anamizu", {37.227904,136.904591}, Prefectures::Ishikawa},
  {553647571, "Nanao", {37.042416,136.963985}, Prefectures::Ishikawa},
  {553646023, "Shigacho", {37.006167,136.778012}, Prefectures::Ishikawa},
  {553636592, "Notobe", {36.961389,136.869612}, Prefectures::Ishikawa},
  {553626724, "Hanesaku", {36.89664,136.78326}, Prefectures::Ishikawa},
  {553605663, "Unoki", {36.722624,136.702879}, Prefectures::Ishikawa},
  {543675602, "Uchinada", {36.633381,136.634268}, Prefectures::Ishikawa},
  {543665912, "Kanazawa", {36.578044,136.648171}, Prefectures::Ishikawa},
  {543664592, "Oshino", {36.541865,136.622088,}, Prefectures::Ishikawa},
  {543664351, "Mattou", {36.52681,136.566371}, Prefectures::Ishikawa},
  {543653462, "Nominegami", {36.452119,136.45954}, Prefectures::Ishikawa},
  {543643861, "Komatsu", {36.40271,136.452831}, Prefectures::Ishikawa},
  {543632881, "Kaga", {36.32055,136.350315}, Prefectures::Ishikawa},

  {543621584, "Ashiwara", {36.214555,136.235015}, Prefectures::Hukui},
  {543611982, "Maruoka", {36.162344,136.233498}, Prefectures::Hukui},
  {543612141, "Matsuoka", {36.094031,136.301845}, Prefectures::Hukui},
  {543601772, "Hukuieki", {36.06165,136.223546}, Prefectures::Hukui},
  {533673794, "Echizenoono", {35.983176,136.496954}, Prefectures::Hukui},
  {533671654, "Kitasabae", {35.971301,136.198583}, Prefectures::Hukui},
  {533671603, "Echizencho", {35.974312,136.129734}, Prefectures::Hukui},
  {533661832, "HukuiTakeo", {35.903455,136.170902}, Prefectures::Hukui},
  {533651953, "HukuiNanjyo", {35.832307,136.193395}, Prefectures::Hukui},
  {533630761, "Suruga", {35.644827,136.076326}, Prefectures::Hukui},
  {533516821, "Obama", {35.485188,135.781118}, Prefectures::Hukui},
  {533514794, "Wakasahongou", {35.482623,135.619313}, Prefectures::Hukui},
  {533514832, "Wakasatakahama", {35.486407,135.547584}, Prefectures::Hukui},

  {533852991, "Nagasaka", {35.826908,138.366269}, Prefectures::Yamanashi},
  {533843561, "Nirasaki", {35.709951,138.451155}, Prefectures::Yamanashi},
  {533845484, "Shioyama", {35.705404,138.734381}, Prefectures::Yamanashi},
  {533837351, "Ootsuki", {35.60942,138.938089}, Prefectures::Yamanashi},
  {533930491, "Uenohara", {35.618479,139.115463}, Prefectures::Yamanashi},
  {533827621, "Tanimuracho", {35.550561,138.904672}, Prefectures::Yamanashi},
  {533826274, "Mitsutouge", {35.524288,138.845517}, Prefectures::Yamanashi},
  {533816914, "Kawaguchiko", {35.498236,138.768841}, Prefectures::Yamanashi},
  {533816832, "Hujisaneki", {35.483549,138.795685}, Prefectures::Yamanashi},
  {533845242, "Yamanashieki", {35.684988,138.682858}, Prefectures::Yamanashi},
  {533835804, "Ishiwaonsen", {35.657664,138.635272}, Prefectures::Yamanashi},
  {533844052, "Kouhueki", {35.666674,138.568785}, Prefectures::Yamanashi},
  {533844012, "Ryuuoueki", {35.668708,138.519373}, Prefectures::Yamanashi},
  {533834422, "Tsunenaga", {35.617075,138.533096}, Prefectures::Yamanashi},
  {533833273, "Minamialps", {35.608395,138.464814}, Prefectures::Yamanashi},
  {533823791, "Ichikawadaimon", {35.560469,138.493379}, Prefectures::Yamanashi},
  {533823762, "Hujikawacho", {35.561175,138.461397}, Prefectures::Yamanashi},

  {553822391, "Kitaiiyama", {36.859037,138.363932}, Prefectures::Nagano},
  {553802991, "Shinshunakano", {36.744772,138.364902}, Prefectures::Nagano},
  {553803833, "Yudanaka", {36.741638,138.414728}, Prefectures::Nagano},
  {553802353, "Kohuse", {36.698941,138.312862}, Prefectures::Nagano},
  {553802142, "Suzaka", {36.678393,138.308684}, Prefectures::Nagano},
  {543871751, "Naganoeki", {36.643124,138.188644}, Prefectures::Nagano},
  {543861303, "Yashiro", {36.531993,138.128097}, Prefectures::Nagano},
  {543851542, "Sakashiro", {36.462421,138.181245}, Prefectures::Nagano},
  {543756094, "Ikedacho", {36.421403,137.874571}, Prefectures::Nagano},
  {543756084, "Shinanomatsukawa", {36.425287,137.858278}, Prefectures::Nagano},
  {543766082, "Shinanooomachi", {36.49992,137.861261}, Prefectures::Nagano},
  {543842703, "Uedaeki", {36.396487,138.249638}, Prefectures::Nagano},
  {543841401, "Aokimura", {36.370077,138.128514}, Prefectures::Nagano},
  {543737621, "Toyoshina", {36.30025,137.90097}, Prefectures::Nagano},
  {543727773, "Matsumoto", {36.230815,137.964355}, Prefectures::Nagano},
  {543717754, "Hirooka", {36.148217,137.949559  }, Prefectures::Nagano},
  {543800864, "Shimosuwa", {36.071984,138.085061}, Prefectures::Nagano},
  {543800634, "Okaya", {36.056985,138.045399}, Prefectures::Nagano},
  {533777791, "Miyaki", {35.976407,137.990649}, Prefectures::Nagano},
  {533871921, "Kayanoeki", {35.9948,138.152503}, Prefectures::Nagano},
  {533871573, "Haramura", {35.958031,138.272589}, Prefectures::Nagano},
  {533767993, "Inamatsushima", {35.913805,137.988631}, Prefectures::Nagano},
  {533767584, "Kitadono", {35.879531,137.984022}, Prefectures::Nagano},
  {533861991, "Hujimieki", {35.912228,138.23786}, Prefectures::Nagano},
  {533767064, "Inaeki", {35.838369,137.959165}, Prefectures::Nagano},
  {533757251, "Miyataeki", {35.767269,137.938944}, Prefectures::Nagano},
  {533747842, "Komagane", {35.736296,137.936782}, Prefectures::Nagano},
  {533747141, "Iijima", {35.678021,137.928799}, Prefectures::Nagano},
  {533755451, "Uematsu", {35.78409,137.693273}, Prefectures::Nagano},
  {533765151, "Kisohukushima", {35.843778,137.69341}, Prefectures::Nagano},
  {533737131, "Inaooshima", {35.595784,137.913261}, Prefectures::Nagano},
  {533727612, "NaganoToyooka", {35.551373,137.896088}, Prefectures::Nagano},
  {533727504, "Ichita", {35.549344,137.886543}, Prefectures::Nagano},
  {533726252, "Iida", {35.519564,137.821249}, Prefectures::Nagano},

  {533666682, "Minoshiratori", {35.884914,136.860593}, Prefectures::Gihu},
  {543712603, "Takayama", {36.141076,137.251365}, Prefectures::Gihu},
  {543721851, "Hidahurukawa", {36.236726,137.189603}, Prefectures::Gihu},
  {533751693, "Gero", {35.921587,137.465382}, Prefectures::Gihu},
  {533720494, "Kamiasou", {35.541425,137.118725}, Prefectures::Gihu},
  {533724001, "Nakatsugawa", {35.500502,137.503153}, Prefectures::Gihu},
  {533713424, "Ena", {35.455097,137.40817}, Prefectures::Gihu},
  {533702401, "Mizunami", {35.36907,137.252033}, Prefectures::Gihu},
  {533701342, "Toki", {35.359764,137.182195}, Prefectures::Gihu},
  {533711711, "Yamozu", {35.476007,137.14143}, Prefectures::Gihu},
  {533711103, "Odaka", {35.429718,137.128229}, Prefectures::Gihu},
  {533700092, "Tajimi", {35.334979,137.121042}, Prefectures::Gihu},
  {533710851, "Nakakawabe", {35.487542,137.065359}, Prefectures::Gihu},
  {533710124, "Imawatarieki", {35.432315,137.037186}, Prefectures::Gihu},
  {533710312, "Minooota", {35.445588,137.019416}, Prefectures::Gihu},
  {533617181, "Sakaiwa", {35.426338,136.976865}, Prefectures::Gihu},
  {533617772, "Toka", {35.47531,136.969319}, Prefectures::Gihu},
  {533627533, "Umeyama", {35.548709,136.917939}, Prefectures::Gihu},
  {533617831, "Hamonokaikan", {35.483542,136.914116}, Prefectures::Gihu},
  {533606862, "Nakaeki", {35.400514,136.835804}, Prefectures::Gihu},
  {533606413, "Kasamatsu", {35.374073,136.764287}, Prefectures::Gihu},
  {533606614, "Ginan", {35.389779,136.769229}, Prefectures::Gihu},
  {533606902, "Gihueki", {35.409528,136.756466}, Prefectures::Gihu},
  {533615434, "Moreragihu", {35.455406,136.670048}, Prefectures::Gihu},
  {533615242, "Kitakatacho", {35.435774,136.684343}, Prefectures::Gihu},
  {533605753, "Hozumi", {35.396082,136.693097}, Prefectures::Gihu},
  {533605031, "Anpachicho", {35.335418,136.665415}, Prefectures::Gihu},
  {523675744, "Shinhatori", {35.315747,136.686397}, Prefectures::Gihu},
  {533615601, "Oonocho", {35.470708,136.627665}, Prefectures::Gihu},
  {533614654, "Ibieki", {35.470237,136.572521}, Prefectures::Gihu},
  {533614352, "Kitaikeno", {35.443434,136.573661}, Prefectures::Gihu},
  {533614081, "Hirokoube", {35.419827,136.602104}, Prefectures::Gihu},
  {533604393, "Oogaki", {35.366778,136.617826}, Prefectures::Gihu},
  {533604421, "Tarui", {35.369692,136.531084}, Prefectures::Gihu},
  {533603374, "Sekigahara", {35.363802,136.470368}, Prefectures::Gihu},
  {523674751, "Minotakada", {35.309061,136.563584}, Prefectures::Gihu},
  {523664683, "Komano", {35.223682,136.603583}, Prefectures::Gihu},

  {523645744, "Nishikuwana", {35.06573,136.683999}, Prefectures::Mie},
  {523645422, "Asahieki", {35.033733,136.657974}, Prefectures::Mie},
  {523645124, "Kwagoetomisubara", {35.016682,136.660154}, Prefectures::Mie},
  {523634691, "Yokkaichi", {34.966323,136.618286}, Prefectures::Mie},
  {523624662, "Suzuka", {34.884064,136.58238}, Prefectures::Mie},
  {523654034, "Taianeki", {35.091982,136.545357}, Prefectures::Mie},
  {523644111, "Komono", {35.008732,136.517376}, Prefectures::Mie},
  {523623491, "Idagawa", {34.86822,136.49255}, Prefectures::Mie},
  {523604802, "Tsueki", {34.733993,136.510243}, Prefectures::Mie},
  {523611201, "Uenoshieki", {34.76755,136.129955}, Prefectures::Mie},
  {513670474, "Meibari", {34.621773,136.095609}, Prefectures::Mie},
  {513664922, "Matsuzaka", {34.576881,136.535564}, Prefectures::Mie},
  {513664493, "Saimiya", {34.537871,136.615218}, Prefectures::Mie},
  {513664032, "Aikaeki", {34.502624,136.545447}, Prefectures::Mie},
  {513655804, "Tamaru", {34.488556,136.634089}, Prefectures::Mie},
  {513655873, "Ujiyamada", {34.488268,136.713961}, Prefectures::Mie},
  {513656871, "Toba", {34.486767,136.843126}, Prefectures::Mie},
  {513636963, "Ukataeki", {34.329317,136.825901}, Prefectures::Mie},
  {513645261, "Minamiiki", {34.352059,136.70365}, Prefectures::Mie},
  {513643722, "Miseyaeki", {34.39477,136.408528}, Prefectures::Mie},
  {513611381, "Aiga", {34.111582,136.227184}, Prefectures::Mie},
  {513601853, "Owase", {34.074725,136.190312}, Prefectures::Mie},

  {533411981, "Tottorieki", {35.493999,134.225896}, Prefectures::Tottori},
  {533317621, "Matsuzaki", {35.46871,133.902042}, Prefectures::Tottori},
  {533402903, "Gunke", {35.413228,134.251365}, Prefectures::Tottori},
  {523471183, "Titou", {35.26526,134.225534}, Prefectures::Tottori},
  {533316474, "Kurayoshi", {35.454752,133.849479}, Prefectures::Tottori},
  {533315953, "Urayasueki", {35.499611,133.693193}, Prefectures::Tottori},
  {533313203, "Hiyoshizu", {35.440182,133.380808}, Prefectures::Tottori},
  {533312064, "Yonago", {35.423417,133.336672}, Prefectures::Tottori},
  {533321483, "Babasaki", {35.538684,133.22641}, Prefectures::Tottori},
  
  {533311164, "Arajima", {35.431774,133.2071}, Prefectures::Shimane},
  {533310632, "Shinjiko", {35.467363,133.046042}, Prefectures::Shimane},
  {533207122, "Kamonaka", {35.344584,132.911241}, Prefectures::Shimane},
  {533206302, "Izumo", {35.361195,132.758592}, Prefectures::Shimane},
  {523263492, "ShimaneOota", {35.200935,132.499685}, Prefectures::Shimane},
  {523241174, "Kouzueki", {35.012746,132.223147}, Prefectures::Shimane},
  {523220871, "Hamadaeki", {34.902571,132.088873}, Prefectures::Shimane},
  {523106171, "Masudaeki", {34.678277,131.839025}, Prefectures::Shimane},

  {523401942, "Nishikatagami", {34.745208,134.184257}, Prefectures::Okayama},
  {523411523, "Wakieki", {34.797285,134.152814}, Prefectures::Okayama},
  {523400071, "Okueki", {34.730723,134.152814}, Prefectures::Okayama},
  {513470922, "Nishiooderaeki", {34.6618,134.037254}, Prefectures::Okayama},
  {513377853, "Kadotayashiki", {34.656158,133.938948}, Prefectures::Okayama},
  {513377934, "Nishikawamidori", {34.665556,133.92312}, Prefectures::Okayama},
  {513377514, "Bizennishi", {34.631919,133.900493}, Prefectures::Okayama},
  {513357961, "Unoeki", {34.494458,133.953868}, Prefectures::Okayama},
  {513376262, "Hayajima", {34.602212,133.833257}, Prefectures::Okayama},
  {513376211, "Kurashiki", {34.60196,133.765753}, Prefectures::Okayama},
  {523305093, "Sousha", {34.67429,133.738077}, Prefectures::Okayama},
  {523314493, "Bityuutakahari", {34.788489,133.616078}, Prefectures::Okayama},
  {513364494, "Kanemitsu", {34.540941,133.620814}, Prefectures::Okayama},
  {513364043, "Satoshoueki", {34.507749,133.550516}, Prefectures::Okayama},
  {513364003, "Kasaoka", {34.504804,133.504464}, Prefectures::Okayama},
  {513373172, "Ihara", {34.592821,133.469103}, Prefectures::Okayama},
  {523345954, "Tyugokukatsuyama", {35.080576,133.694679}, Prefectures::Okayama},
  {523337964, "Kikkoueki", {34.998619,133.959102}, Prefectures::Okayama},
  {523440722, "Higashitsuyama", {35.058669,134.031816}, Prefectures::Okayama},
  {523440492, "Katsumata", {35.035785,134.118809}, Prefectures::Okayama},
  {523451443, "Nagicho", {35.123024,134.177426}, Prefectures::Okayama},

  {513221472, "Wagicho", {34.202432,132.220288}, Prefectures::Yamaguchi},
  {513221083, "Iwakuni", {34.171957,132.225028}, Prefectures::Yamaguchi},
  {503271152, "Subouooshima", {33.927631,132.19532}, Prefectures::Yamaguchi},
  {503270583, "Yanagii", {33.965853,132.106398}, Prefectures::Yamaguchi},
  {503270254, "Heiseicho", {33.938056,132.073056}, Prefectures::Yamaguchi},
  {503270532, "Tahusecho", {33.958725,132.043834}, Prefectures::Yamaguchi},
  {503177633, "Hikarieki", {33.973943,131.914817}, Prefectures::Yamaguchi},
  {513106191, "Shimomatsu", {34.008728,131.868056}, Prefectures::Yamaguchi},
  {513106641, "Tokuyamaeki", {34.051162,131.802991}, Prefectures::Yamaguchi},
  {513104652, "Bouhu", {34.053399,131.568457}, Prefectures::Yamaguchi},
  {513123083, "Yamaguchieki", {34.176454,131.474183}, Prefectures::Yamaguchi},
  {503172401, "Kotoshiba", {33.952654,131.252433}, Prefectures::Yamaguchi},
  {513101044, "Onoda", {34.007813,131.185548}, Prefectures::Yamaguchi},
  {503077334, "Shimonoseki", {33.950577,130.922101}, Prefectures::Yamaguchi},
  {513121061, "Miroku", {34.169198,131.204445}, Prefectures::Yamaguchi},
  {513141542, "Nagato", {34.375324,131.185052}, Prefectures::Yamaguchi},
  {513153022, "Higashihagi", {34.417019,131.410366}, Prefectures::Yamaguchi},

  {502917373, "Karatsu", {33.445938,129.968507}, Prefectures::Saga},
  {492977203, "Imari", {33.271873,129.876298}, Prefectures::Saga},
  {493070482, "Nakataku", {33.28332,130.112221}, Prefectures::Saga},
  {503014222, "Keyakidaieki", {33.434116,130.533401}, Prefectures::Saga},
  {503004612, "Tashiro", {33.383989,130.524512}, Prefectures::Saga},
  {493064843, "Hirokawacho", {33.241698,130.551147}, Prefectures::Saga},
  {493064542, "Yame", {33.211939,130.557874}, Prefectures::Saga},
  {493063592, "Hainuzuka", {33.209947,130.497604}, Prefectures::Saga},
  {493053884, "Setaka", {33.157147,130.485385}, Prefectures::Saga},
  {493063033, "Yakabe", {33.173889,130.415682}, Prefectures::Saga},
  {493063551, "Hattyoumuta", {33.208918,130.437582}, Prefectures::Saga},
  {493050374, "Bizenkashima", {33.114459,130.097808}, Prefectures::Saga},
  {493050542, "Ureshino", {33.100892,129.987055}, Prefectures::Saga},
  {493060314, "Takeo", {33.19647,130.023086}, Prefectures::Saga},  
  {493060582, "Oomachichoeki", {33.212412,130.106473}, Prefectures::Saga},
  {493060593, "Oomachichoyakuba", {33.213759,130.1161}, Prefectures::Saga},
  {493061622, "Bizenyamaguchi", {33.219393,130.160758}, Prefectures::Saga},
  {493061963, "Ushitsu", {33.247826,130.201547}, Prefectures::Saga},
  {493072134, "Sagaeki", {33.264176,130.297397}, Prefectures::Saga},
  {493072794, "Kamisaki", {33.315766,130.374474}, Prefectures::Saga},
  {503003153, "Nakaharaeki", {33.346342,130.440411}, Prefectures::Saga},
  {493073814, "Yoshinosato", {33.324845,130.399378}, Prefectures::Saga},

  {502945953, "Ichiki", {33.749967,129.691357}, Prefectures::Nagasaki},
  {502905162, "Matsuura", {33.34425,129.707839}, Prefectures::Nagasaki},
  {502904364, "Tabirahirado", {33.362607,129.582711}, Prefectures::Nagasaki},
  {492965812, "Sasaeki", {33.236734,129.646875}, Prefectures::Nagasaki},
  {492965074, "Sasebo", {33.170937,129.720537}, Prefectures::Nagasaki},
  {492957614, "Hasamicho", {33.137893,129.895548}, Prefectures::Nagasaki},
  {492946891, "Kawadana", {33.06846,129.863442}, Prefectures::Nagasaki},
  {492927962, "Oomura", {32.910748,129.962203}, Prefectures::Nagasaki},
  {493020231, "Isahaya", {32.852064,130.041238}, Prefectures::Nagasaki},
  {492916972, "Tokitsucho", {32.828751,129.848546}, Prefectures::Nagasaki},
  {492916683, "Michinoo", {32.804386,129.852857}, Prefectures::Nagasaki},
  {492907901, "Kankoudoorieki", {32.743298,129.878013}, Prefectures::Nagasaki},
  {493011821, "NagasakiAinoeki", {32.818944,130.156049}, Prefectures::Nagasaki},
  {493012494, "Shimabara", {32.790237,130.370656}, Prefectures::Nagasaki},
  {483072932, "Minamishimabara", {32.659796,130.297847}, Prefectures::Nagasaki},

  {493044731, "Nankancho", {33.061605,130.540972}, Prefectures::Kumamoto},
  {493033942, "Arao", {32.994287,130.434236}, Prefectures::Kumamoto},
  {493033261, "Nagasu", {32.935617,130.45432}, Prefectures::Kumamoto},
  {493034132, "Tamana", {32.926161,130.549355}, Prefectures::Kumamoto},
  {493025903, "Koppa", {32.916344,130.626295}, Prefectures::Kumamoto},
  {493045153, "Yamashika", {33.017499,130.691216}, Prefectures::Kumamoto},
  {493150453, "Ogunicho", {33.121582,131.068152}, Prefectures::Kumamoto},
  {493130291, "Miyajieki", {32.937259,131.117548}, Prefectures::Kumamoto},
  {493026591, "Higoootsu", {32.877436,130.866191}, Prefectures::Kumamoto},
  {493026332, "Misatoki", {32.861787,130.797045}, Prefectures::Kumamoto},
  {493026224, "Hikarinomori", {32.857687,130.786755}, Prefectures::Kumamoto},
  {493025393, "Mitsuishi", {32.864157,130.738342}, Prefectures::Kumamoto},
  {493027021, "Nishihara", {32.834814,130.903007}, Prefectures::Kumamoto},
  {493110892, "Takamori", {32.819336,131.122476}, Prefectures::Kumamoto},
  {493015662, "Tsuuchosuji", {32.803275,130.70968}, Prefectures::Kumamoto},
  {493015453, "Kumamotoeki", {32.790193,130.689915}, Prefectures::Kumamoto},
  {493016453, "Masujyoucho", {32.791403,130.81637}, Prefectures::Kumamoto},
  {493016302, "Kenguncho", {32.77831,130.76082}, Prefectures::Kumamoto},
  {493015144, "Nishikumamotoeki", {32.762557,130.682961}, Prefectures::Kumamoto},
  {493006543, "Ohunacho", {32.714554,130.801936}, Prefectures::Kumamoto},
  {483075832, "Matsuhashi", {32.652458,130.670409}, Prefectures::Kumamoto},
  {483076842, "Kousa", {32.65122,130.81129}, Prefectures::Kumamoto},
  {483076633, "KumamotoMisatocho", {32.6397,130.788901}, Prefectures::Kumamoto},
  {483065934, "Hikawacho", {32.582453,130.673737}, Prefectures::Kumamoto},
  {483073043, "Kamiamakusa", {32.587382,130.430457}, Prefectures::Kumamoto},
  {483051551, "Amakusa", {32.458457,130.193344}, Prefectures::Kumamoto},
  {483054782, "Bigotakada", {32.475116,130.612364}, Prefectures::Kumamoto},
  {483023414, "Minamata", {32.204948,130.396084}, Prefectures::Kumamoto},
  {483026503, "Hitoyoshi", {32.21612,130.753719}, Prefectures::Kumamoto},
  {483027811, "Asagiri", {32.236259,130.893817}, Prefectures::Kumamoto},
  {483037144, "Taraki", {32.262812,130.933174}, Prefectures::Kumamoto},

  {483021343, "Nagashimacho", {32.199343,130.176784}, Prefectures::Kagoshima},  
  {483002971, "Nishiidemitzu", {32.075406,130.339231}, Prefectures::Kagoshima},
  {483001254, "Akune", {32.022947,130.196237}, Prefectures::Kagoshima},
  {483004693, "Isa", {32.057195,130.613066}, Prefectures::Kagoshima},
  {473075472, "Kurino", {31.950538,130.723311}, Prefectures::Kagoshima},
  {473052744, "Sendai", {31.813716,130.312237}, Prefectures::Kagoshima},
  {473042614, "Kushikino", {31.721334,130.274188}, Prefectures::Kagoshima},
  {473033514, "Ijuuin", {31.630235,130.395793}, Prefectures::Kagoshima},
  {473034043, "Tenmonkantsu", {31.590658,130.555058}, Prefectures::Kagoshima},
  {473012052, "Minamisatsuma", {31.416601,130.323485}, Prefectures::Kagoshima},
  {463072234, "Makurazaki", {31.272014,130.299539}, Prefectures::Kagoshima},
  {463073033, "Eiookawa", {31.257887,130.4133}, Prefectures::Kagoshima},
  {463065811, "Ibusuki", {31.236949,130.642586}, Prefectures::Kagoshima},
  {473045702, "Tyousa", {31.72695,130.63277}, Prefectures::Kagoshima},
  {473046911, "Kokubun", {31.743599,130.763391}, Prefectures::Kagoshima},
  {473015961, "Tarumizu", {31.492862,130.700797}, Prefectures::Kagoshima},
  {473006581, "Shikaya", {31.378205,130.852177}, Prefectures::Kagoshima},
  {473007152, "Kimotsuke", {31.344364,130.945223}, Prefectures::Kagoshima},
  {463066931, "Nishikie", {31.243572,130.787615}, Prefectures::Kagoshima},
  {463066611, "Minamioosumi", {31.217288,130.768172}, Prefectures::Kagoshima},
  {473110674, "Shihushi", {31.473098,131.098346}, Prefectures::Kagoshima},

  {473111583, "Kushima", {31.462963,131.230557}, Prefectures::Miyazaki},
  {473133012, "Yutsu", {31.586785,131.395984}, Prefectures::Miyazaki},
  {473140644, "Nishitojyou", {31.723542,131.05701}, Prefectures::Miyazaki},
  {473140892, "Mimata", {31.733792,131.119476}, Prefectures::Miyazaki},
  {473163732, "Minamimiyazaki", {31.895116,131.422359}, Prefectures::Miyazaki},
  {473077883, "Kobayashi", {31.990594,130.976149}, Prefectures::Miyazaki},
  {473172854, "Kokutomicho", {31.990649,131.323535}, Prefectures::Miyazaki},
  {483104803, "Hyuugashintomi", {32.072511,131.501906}, Prefectures::Miyazaki},
  {483113321, "Nishimiyako", {32.1078,131.400992}, Prefectures::Miyazaki},
  {483114424, "Takanabe", {32.122263,131.533494}, Prefectures::Miyazaki},
  {483006511, "Kyoumachionsen", {32.045396,130.767668}, Prefectures::Miyazaki},
  {483134051, "Tonoueki", {32.250864,131.568088}, Prefectures::Miyazaki},
  {483155101, "Hyuugashieki", {32.425792,131.627937}, Prefectures::Miyazaki},
  {483155721, "Kadokawaeki", {32.477353,131.653841}, Prefectures::Miyazaki},
  {483175034, "Nobeoka", {32.589956,131.672405}, Prefectures::Miyazaki},
  {493102542, "Takachiho", {32.711738,131.307797}, Prefectures::Miyazaki},


  {493136484, "Kamioka", {32.95628,131.861628}, Prefectures::Ooita},
  {493134862, "Miecho", {32.983603,131.584366}, Prefectures::Ooita},
  {493133613, "Bungotakeda", {32.970797,131.389726}, Prefectures::Ooita},
  {493146893, "Tsukumi", {33.072933,131.863708}, Prefectures::Ooita},
  {493156442, "Usuki", {33.118594,131.807767}, Prefectures::Ooita},
  {493164313, "Mukounohara", {33.196801,131.513986}, Prefectures::Ooita},
  {493164783, "Ooitaeki", {33.23316,131.606392}, Prefectures::Ooita},
  {493174303, "Beppu", {33.279584,131.500607}, Prefectures::Ooita},
  {493171323, "Bunngomorieki", {33.282656,131.155453}, Prefectures::Ooita},
  {493077851, "Hidaeki", {33.317021,130.938733}, Prefectures::Ooita},
  {503104421, "Youkoku", {33.370115,131.530563}, Prefectures::Ooita},
  {503114303, "Nakayamakaori", {33.44854,131.505751}, Prefectures::Ooita},
  {503131153, "Nakatsueki", {33.599166,131.190782}, Prefectures::Ooita},
  {503123704, "Bungonagasu", {33.564868,131.382876}, Prefectures::Ooita},
  {503123654, "Bungotakada", {33.556173,131.447046}, Prefectures::Ooita},
  {503125784, "Kokutou", {33.563269,131.732218}, Prefectures::Ooita},

  {513357592, "Tyokutoucho", {34.459796,133.995634}, Prefectures::Kagawa},  
  {513451842, "Doshoucho", {34.486783,134.188298}, Prefectures::Kagawa},  
  {513440043, "Kawaracho", {34.338961,134.052558}, Prefectures::Kagawa},
  {513431834, "Kotodenshido", {34.322537,134.172956}, Prefectures::Kagawa},
  {513336784, "Sakaide", {34.313167,133.856717}, Prefectures::Kagawa},
  {513336653, "Utatsu", {34.30636,133.813896}, Prefectures::Kagawa},
  {513336531, "Marugame", {34.291974,133.792917}, Prefectures::Kagawa},
  {513336204, "Tadotsu", {34.271102,133.75673}, Prefectures::Kagawa},
  {513327934, "Takimiya", {34.248146,133.922165}, Prefectures::Kagawa},
  {513431202, "Gakuendoorieki", {34.270573,134.136917}, Prefectures::Kagawa},
  {513432062, "Sanbonmatsu", {34.251568,134.334466}, Prefectures::Kagawa},
  {513326733, "Zentsuuji", {34.229953,133.789225}, Prefectures::Kagawa},
  {513326254, "Kotodenkotohira", {34.190891,133.819243}, Prefectures::Kagawa},
  {513325262, "Takaseeki", {34.184074,133.71142}, Prefectures::Kagawa},
  {513315423, "Kannonji", {34.124436,133.655514}, Prefectures::Kagawa},
  
  {513424184, "Naruto", {34.179227,134.608584}, Prefectures::Tokushima},
  {513413771, "Itano", {34.142188,134.465922}, Prefectures::Tokushima},
  {513414661, "Matsushigecho", {34.133784,134.580563}, Prefectures::Tokushima},
  {513414532, "Kitajimacho", {34.12558,134.547007}, Prefectures::Tokushima},
  {513414521, "Katsuho", {34.128655,134.528264}, Prefectures::Tokushima},
  {513413423, "Kamiita", {34.121453,134.404929}, Prefectures::Tokushima},
  {513404843, "Tokushimaeki", {34.074235,134.551158}, Prefectures::Tokushima},
  {513403852, "Ishiieki", {34.070212,134.44431}, Prefectures::Tokushima},
  {513402884, "Kamoshima", {34.073617,134.356501}, Prefectures::Tokushima},
  {513401984, "Awa", {34.089293,134.234111}, Prefectures::Tokushima},
  {513400444, "Sadamitsu", {34.039368,134.058787}, Prefectures::Tokushima},
  {513307441, "Awakamo", {34.037064,133.926485}, Prefectures::Tokushima},
  {513306341, "Awaikeda", {34.027107,133.804717}, Prefectures::Tokushima},
  {503422841, "Shishikui", {33.566734,134.30059}, Prefectures::Tokushima},  

  {513207793, "Imabari", {34.064339,132.99378}, Prefectures::Ehime},
  {503372334, "Niihama", {33.948045,133.294363}, Prefectures::Ehime},
  {503374733, "Iyomishima", {33.979575,133.541997}, Prefectures::Ehime},
  {503361953, "Iyosaijyou", {33.912501,133.187561}, Prefectures::Ehime},
  {503266011, "Matsuyama", {33.835615,132.762051}, Prefectures::Ehime},
  {503257602, "Yokogawara", {33.803336,132.884283}, Prefectures::Ehime},
  {503255363, "Jizoucho", {33.779537,132.70421}, Prefectures::Ehime},
  {503255063, "Gunnakaminato", {33.756066,132.702129}, Prefectures::Ehime},
  {503246933, "Tobecho", {33.74926,132.792233}, Prefectures::Ehime},
  {503237823, "Kumankougen", {33.655721,132.901523}, Prefectures::Ehime},
  {503225514, "Naishi", {33.548928,132.646304}, Prefectures::Ehime},
  {503224232, "Iyooosu", {33.51848,132.544802}, Prefectures::Ehime},
  {503213444, "Yawatahama", {33.458164,132.436012}, Prefectures::Ehime},
  {503204304, "Unocho", {33.363196,132.509904}, Prefectures::Ehime},
  {493275043, "Chikanaga", {33.255706,132.67635}, Prefectures::Ehime},
  {493264751, "Uwajima", {33.226069,132.567642}, Prefectures::Ehime},
  {493234562, "Ainancho", {32.962517,132.58342}, Prefectures::Ehime},

  {503327024, "Akieki", {33.504424,133.906399}, Prefectures::Kouchi},
  {503410111, "Nahanri", {33.42503,134.018081}, Prefectures::Kouchi},
  {493471423, "Muroto", {33.289854,134.15205}, Prefectures::Kouchi},
  {503335244, "Tosayamada", {33.607105,133.684643}, Prefectures::Kouchi},
  {503325752, "Noichi", {33.561828,133.698055}, Prefectures::Kouchi},
  {503325814, "Gomenhigashi", {33.574533,133.647874}, Prefectures::Kouchi},
  {503324722, "Kouchijyou", {33.558518,133.534223}, Prefectures::Kouchi},
  {503323543, "Inoeki", {33.547505,133.430098}, Prefectures::Kouchi},
  {503313943, "Tosa", {33.494482,133.424274}, Prefectures::Kouchi},
  {503322303, "Echicho", {33.532862,133.252108}, Prefectures::Kouchi},
  {503322031, "Sagawaeki", {33.500101,133.292518}, Prefectures::Kouchi},
  {503302932, "Tanogou", {33.410417,133.296875}, Prefectures::Kouchi},
  {493371981, "Tosakurei", {33.329312,133.226799}, Prefectures::Kouchi},
  {493361504, "Tubokawa", {33.212328,133.137357}, Prefectures::Kouchi},
  {493237852, "Nakamuraeki", {32.984576,132.943976}, Prefectures::Kouchi},
  {493235281, "Higashishukumou", {32.933605,132.728663}, Prefectures::Kouchi},
  {493217363, "Tosashimizu", {32.781463,132.954834}, Prefectures::Kouchi},
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
    os << "wdog.exe -v xdotool mousemove --window " << wid << ' ';
    os << pos(kind) << ' ' << 490;
    auto x = system(os.str().c_str());
    if (x) {
      cerr << os.str() << " failed\n";
      return true;
    }
    const char* cmd = "wdog.exe -v xdotool click 1";
    auto y = system(cmd);
    if (y) {
      cerr << cmd << " failed\n";
      return true;
    }
  }
  string fn = dump_file(info.place, kind);
 label:
  ostringstream osz;
  osz << "wdog.exe -v xwd -id " << wid << " -out " << fn << " -silent";
  auto z = system(osz.str().c_str());
  if (z) {
    cerr << osz.str() << " failed\n";
    return true;
  }

  ostringstream os;
  auto c = info.coord;
  os << "wdog.exe -v " << prog(kind) << " -in " << fn;
  os << " -x " << c.first;
  os << " -y " << c.second;
  os << " -p " << to_string(info.pref);
  auto ofn = fn + ".cpp";
  os << " > " << ofn;
  auto u = system(os.str().c_str());
  if (u) {
    static map<string, int> retry;
    if (retry[fn]++ > 2) {
      cerr << os.str() << " failed\n";
      unlink(ofn.c_str());
      return true;
    }
    cerr << "sleep 5\n"; sleep(5);
    goto label;
  }
  unlink(fn.c_str());
  
  ostringstream os2;
  os2 << "wdog.exe -v g++ -c -fPIC " << ofn;
  auto v = system(os2.str().c_str());
#if 0  
  assert(v == 0);
#endif  
  return false;
}

inline bool close_tab(std::string wid)
{
  using namespace std;
  ostringstream os;
  os << "wdog.exe -v xdotool mousemove --window " << wid << " 210 10";
  auto x = system(os.str().c_str());
  if (x) {
    cerr << os.str() << " failed\n";
    return true;
  }
  const char* cmd = "wdog.exe -v xdotool click 1";
  auto y = system(cmd);
  if (y) {
    cerr << cmd << " failed\n";
    return true;
  }
  return false;
}

inline std::string get_wid(int id)
{
  using namespace std;
  // 10 : enough, 5 : work well
  cerr << "sleep 5"; sleep(5);
  ostringstream os;
  os << "w." << id;
  string log = os.str();
  string cmd = "wdog.exe -v ";
  cmd += "xwininfo -root -tree | grep 'モバイル空間統計' | grep 999x619";
  cmd += " | awk '{print $1}' > ";
  cmd += log;
  auto y = system(cmd.c_str());
  if (y) {
    cerr << cmd << " failed\n";
    exit(1);
  }
  ifstream ifs(log);
  string wid;
  ifs >> wid;
  unlink(log.c_str());
  return wid;
}

inline bool subr(const info_t& info)
{
  using namespace std;
  {
    ostringstream os;
    os << "wdog.exe -v firefox https://tokyo.mobakumap.jp/#" << info.id;
    auto fire = os.str();
    if (system(fire.c_str())) {
      cerr << fire << " failed\n";
      exit(1);
    }
  }
  string wid;
  while (wid.empty())
    wid = get_wid(info.id);
  auto rt = capture(wid, info, time_s);
  auto rg = capture(wid, info, generation);
  auto rp = capture(wid, info, place);
  auto rc = close_tab(wid);
  return rt || rg || rp || rc;
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

inline bool comp_pref(info_t info, Prefectures pref)
{
  return info.pref == pref;
}

int main(int argc, char** argv)
{
  using namespace std;
  check_valid();
  
  string s, e;
  bool ignore = false;
  bool next_f = false;
  string pref;
  for (int opt ; (opt = getopt(argc, argv, "s:e:i012j:n:p:")) != -1 ; ) {
    switch (opt) {
    case 's': s = optarg; break;
    case 'e': e = optarg; break;
    case 'i': ignore = true; break;
    case 'j': s = e = optarg; break;
    case 'n': s = optarg; next_f = true; break;
    case 'p': pref = optarg; break;
    case '0': s = "Nihonbashi"; e = "Numata"; break;
    case '1': s = "Umeda"; e = "Yamashina"; break;
    case '2': s = "OkinawaKentyou"; break;
    default: usage(argv[0]); return 1;
    }
  }

  if (optind != argc) {
    usage(argv[0]);
    return 1;
  }
    
  pid_t pid = fork();
  if (!pid) {
    execl("/usr/bin/firefox", "firefox",
	  "https://tokyo.mobakumap.jp/", nullptr);
    cerr << "execl failed\n";
    return 1;
  }
  cerr << "sleep 30"; sleep(30);

  auto ss = begin(data);
  if (!s.empty()) {
    auto p = find_if(begin(data), end(data), bind2nd(ptr_fun(comp), s));
    if (p == end(data)) {
      cerr << '`' << s << "' not found\n";
      return 1;
    }
    if (next_f)
      ++p;
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
  if (!pref.empty()) {
    auto x = from_string(pref);
    ss = find_if(ss, ee, bind2nd(ptr_fun(comp_pref), x));
    assert(ss != ee);
    ee = find_if(ss, ee, not1(bind2nd(ptr_fun(comp_pref), x)));
  }

  auto p = find_if(ss, ee, subr);
  auto ret = ee - p;
  if (!ignore || !ret)
    return ret;
  
  for_each(p+1, ee, subr);
  return ret;
}
