#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <set>

struct info_t {
  int id;
  std::string place;
  std::pair<double, double> coord;
};

std::vector<info_t> data = {
  {533946114, "Nihonbashi", {35.68123,139.774534}},
  {533946113, "Marunouchi", {35.680478,139.765367}},
#if 1
  {533946211, "Ootemachi", {35.687438,139.764955}},
  {533946013, "Ginza", {35.669626,139.765539}},
  {533936904, "Shinbashi", {35.664917,139.757003}},
  {533946001, "Toranomon", {35.665949,139.74625}},
  {533946411, "Ochanomizu", {35.718733,139.731683}},
  {533946521, "Ueno", {35.711622,139.775695}},
  {533946532, "Asakusa", {35.717064,139.79875}},
  {533946542, "Skytree", {35.710063,139.8107}},
  {533946353, "Kinshicho", {35.698312,139.813998}},
  {533936834, "Toyosu", {35.652026,139.788785}},
  {533936833, "RaraportToyosu", {35.655735,139.792662}},
  {533935981, "Roppongi", {35.662893,139.733651}},
  {533935961, "Shibuya", {35.661633,139.702516}},
  {533935952, "Centergai", {35.658034,139.701636}},
  {533935853, "Kamiizumi", {35.65727,139.693623}},
  {533945052, "Yoyogikouen", {35.671587,139.696703}},
  {533945254, "ShinjukuNishi", {35.693292,139.699132}},
  {533945263, "ShinjukuHigashi", {35.689607,139.700571}},
  {533945361, "Kabukicho", {35.695543,139.703149}},
  {533945764, "Ikebukuro", {35.736262,139.707009}},
  {533945433, "Nakano", {35.70607,139.659262}},
  {533945963, "Ohyamaeki", {35.748531,139.702286}},
  {533946712, "Nippori", {35.728158,139.770641}},
  {533946943, "Kitasenju", {35.753029,139.803752}},
  {533936521, "Daiba", {35.61885,139.780188}},
  {533935591, "Shinagawa", {35.628471,139.73876}},
  {533935481, "Ohsaki", {35.619851,139.728189}},
  {533925771, "Kamata", {35.562479,139.716073}},
  {533926524, "Haneda", {35.549393,139.779839}},
  {533935732, "Sangenchaya", {35.641285,139.667989,}},
  {533932873, "Hachioji", {35.658566,139.295838}},
  {533933931, "Takahatahudo", {35.662013,139.411074}},
  {533943083, "Huchu", {35.673204,139.477815}},
  {533934601, "Inagi", {35.628468,139.494632}},
  {533934832, "Chohu", {35.660425,139.555081}},
  {533934662, "Kitami", {35.636547,139.587245}},
  {533944494, "Ogikubo", {35.697402,139.622517}},
  {533944461, "Kichijoji", {35.703158,139.580115}},
  {533944442, "Mitaka", {35.683546,139.559268}},
  {533944402, "MusashiKoganei", {35.701123,139.506912}},
  {533943481, "Kokubunji", {35.705538,139.460007}},
  {533943333, "Tachikawa", {35.714188,139.399159}},
  {533942584, "Akishima", {35.708829,139.364915}},
  {533942722, "Akikawa", {35.728027,139.286749}},
  {533942902, "Hinodecho", {35.742117,139.257405}},
  {533942961, "Hussa", {35.742364,139.327865}},
  {533952274, "Hakonesaki", {35.771312,139.346714}},
  {533952341, "Kosaku", {35.777083,139.303125}},
  {533952422, "Kawabe", {35.785417,139.284375}},
  {533954214, "Kiyose", {35.784283,139.521967}},
  {533954122, "Higashikurume", {35.753218,139.516371}},
  {533943974, "Kumekawa", {35.750026,139.472007}},
  {533944731, "Tanashi", {35.727083,139.540625}},
  {533943683, "Hitotsubashigakuen", {35.72206,139.480039}},
  {533945821, "Nerima", {35.735785,139.651776}},
  {533955372, "Akabane", {35.783721,139.7217}},
  {533956174, "Kameari", {35.761606,139.848806}},
  {533936984, "Nishikasai", {35.664577,139.859203}},

  {533925354, "Kawasaki", {35.532988,139.700872}},
  {533925363, "KeikyuKawasaki", {35.531365,139.696889}},
  {533925141, "Tsurumi", {35.508036,139.676262}},
  {533924191, "Shinyokohama", {35.508043,139.614786}},
  {533915603, "Kanagawaeki", {35.471027,139.627114}},
  {533914594, "Yokohama", {35.465981,139.622062}},
  {533915313, "NipponOhdouri", {35.446456,139.642306}},
  {533914474, "Hoshikawa", {35.458875,139.589907}},
  {533914291, "Yoshinocho", {35.435417,139.615625}},
  {533904972, "Kamiohoka", {35.409122,139.596629}},
  {533904192, "Kanazawabunko", {35.343905,139.628711}},
  {523974841, "Kamakura", {35.319065,139.550412}},
  {523975332, "Yokosukachuo", {35.278699,139.67004}},
  {523974561, "Shinzushi", {35.295934,139.581199}},
  {523974264, "Hayamacho", {35.272094,139.586202}},
  {533903084, "Hujisawa", {35.338898,139.48747}},
  {533903084, "Oohuna", {35.354048,139.531299}},
  {533904822, "Totsuka", {35.400766,139.534204}},
  {533904903, "Tateba", {35.414484,139.500994}},
  {533903402, "Samukawacho", {35.37595,139.387012}},
  {523973924, "Chigasaki", {35.330303,139.406817}},
  {523972972, "Hiratsuka", {35.32783,139.350645}},
  {523972751, "Ohiso", {35.311435,139.313291}},
  {523972504, "Ninomiya", {35.298786,139.257598}},
  {523971023, "Odawara", {35.256445,139.155393}},
  {533902414, "Tokaidaigaku", {35.372872,139.270904}},
  {533902753, "Isehara", {35.396037,139.313594}},
  {533912293, "Hon-atsugi", {35.439408,139.364422}},
  {533913411, "Ebina", {35.454271,139.389335}},
  {533913662, "Yamato", {35.469831,139.461463}},
  {533913682, "Seya", {35.473081,139.475668}},
  {533913241, "Ayase", {35.437553,139.430111}},
  {533923134, "OdakyuSagamihara", {35.515191,139.422653}},
  {533923353, "Sagamiohno", {35.532641,139.433562}},
  {533923552, "Machida", {35.541994,139.445376}},
  {533924942, "Tamapraza", {35.577406,139.558528}},
  {533924552, "CenterMinami", {35.545583,139.57451}},
  {533925922, "MusashiKosugi", {35.576629,139.66}},
  {533934071, "Miyazakidai", {35.587217,139.591201}},
  {533934184, "Mizonokuchi", {35.599965,139.610623}},
  {533934452, "Noborido", {35.620766,139.570098}},
  {533934202, "Shinyuri", {35.603805,139.507605}},
  {533923812, "Huchinobe", {35.568734,139.3951}},
  {533932172, "Hashimoto", {35.594864,139.344922}},
  {533922352, "Aikawacho", {35.528821,139.321661}},
  {533933434, "Tamacenter", {35.623931,139.422853}},

  {533955671, "Kawaguchi", {35.833731,139.731689}},
  {533955643, "Toda", {35.801922,139.66835}},
  {533954493, "Wakou", {35.789853,139.62211}},
  {533954642, "Niiza", {35.803692,139.556495}},
  {533954764, "Asakasumidai", {35.814553,139.587081}},
  {533964061, "Shigishi", {35.839701,139.581411}},
  {533954921, "Miyoshicho", {35.833067,139.51686}},
  {533964312, "Hujiminoshi", {35.867403,139.509741}},
  {533964404, "Kamihukuokaeki", {35.873915,139.511741}},
  {533963884, "Kawagoe", {35.907116,139.482444}},
  {533974051, "Sashiohgieki", {35.91693,139.56494}},
  {533953472, "Tokorozawa", {35.786617,139.473225}},
  {533953004, "MusashiMurayama", {35.753403,139.384666}},
  {533943833, "Sakurakaidoueki", {35.738918,139.416682}},
  {533953833, "MusashiHujisawa", {35.820853,139.412763}},
  {533955951, "Warabi", {35.824611,139.686419}},
  {533956941, "Souka", {35.828478,139.803594}},
  {533956674, "Yashio", {35.807836,139.844826}},
  {533957803, "Misato", {35.825964,139.875843}},
  {533966571, "Yoshikawa", {35.876664,139.843224}},
  {533966531, "Koshigaya", {35.875611,139.789783}},
  {533965363, "HigashiUrawa", {35.864132,139.704639}},
  {533965322, "Urawa", {35.859044,139.657217}},
  {533965112, "MusashiUrawa", {35.845957,139.647629}},
  {533965101, "NishiUrawa", {35.844278,139.628025}},
  {533965603, "Yono", {35.89078,139.628681}},
  {533964894, "Ohmiya", {35.906449,139.623855}},
  {533974284, "Miyaharaeki", {35.940292,139.609571}},
  {533975313, "HigashiOhmiya", {35.948755,139.640286}},
  {533975564, "Iwatsuki", {35.96334,139.712229}},
  {533976703, "Kasukabe", {35.979918,139.752621}},
  {533975723, "Hasuda", {35.981286,139.653069}},
  {533974673, "Ageo", {35.973522,139.588818}},
  {533974993, "Inachuo", {35.999422,139.61721}},
  {533974953, "Okegawa", {35.998756,139.564032}},
  {543904324, "Kitamoto", {36.031574,139.534009}},
  {543904702, "Kounosu", {36.059241,139.509643}},
  {543903463, "Yoshimicho", {36.039853,139.45373}},
  {543903421, "HigashiMatsuyama", {36.034875,139.401776}},
  {543903501, "ShinrinKoueneki", {36.045234,139.374902}},
  {543902561, "MusashiArashiyama", {36.044381,139.32765}},
  {543902031, "Meikakueki", {36.003341,139.288854}},
  {543902702, "Ogawachoeki", {36.058417,139.261343}},
  {543911451, "Yoriieki", {36.117887,139.194537}},
  {543910382, "Nogamieki", {36.11159,139.111193}},
  {543900981, "Oyahanaeki", {36.077566,139.106306}},
  {533970962, "Ohanabatakeeki", {35.992492,139.083617}},
  {533970872, "Yokose", {35.968188,139.132708}},
  {533972534, "Ogose", {35.962165,139.299375}},
  {533972361, "BushuNagaseeki", {35.941979,139.325765}},
  {533973324, "Wakabaeki", {35.949105,139.40873}},
  {533973614, "Kitasakado", {35.971836,139.396702}},
  {543913344, "Gyoda", {36.113765,139.432249}},
  {543913613, "Kumagaya", {36.13939,139.390033}},
  {543924022, "Hanyu", {36.170361,139.534104}},
  {543922224, "Hukaya", {36.191419,139.281398}},
  {543921851, "Honjyo", {36.236164,139.188611}},
  {543931012, "Jinbobara", {36.253464,139.149407}},
  {543920583, "Tansou", {36.216661,139.102273}},
  {543915302, "Hanasaki", {36.109925,139.633523}},
  {543905873, "Satte", {36.074555,139.714949}},
  {543905743, "Kuki", {36.065958,139.677633}},
  {543905671, "SugidoTakanodai", {36.051502,139.714422}},
  {543905283, "ToubuDoubutsuKouen", {36.02495,139.7267}},
  {543905231, "Shiraoka", {36.017588,139.667094}},

  {533937601, "DisneyLand", {35.632896,139.880394}},
  {533947643, "Honyawata", {35.721091,139.927234}},
  {533947482, "Hunabashi", {35.701736,139.985382}},
  {534040214, "Tsudanuma", {35.691215,140.020407}},
  {534030941, "KeiseiMakuhari", {35.660444,140.056076}},
  {534030733, "KaihinMakuhari", {35.648476,140.041987}},
  {534030673, "Inage", {35.63717,140.09249}},
  {534031612, "Tsuga", {35.636095,140.149201}},
  {534030391, "KeiseiChiba", {35.611618,140.114267}},
  {534021741, "Kamatori", {35.562653,140.178736}},
  {534020173, "Goieki", {35.513028,140.089701}},
  {533917164, "Sodegaura", {35.432189,139.957829}},
  {533907543, "Kisarazu", {35.381579,139.926229}},
  {533907012, "Kimitsu", {35.333667,139.895042}},
  {523976984, "Aobori", {35.330531,139.858939}},
  {523956364, "Katsuyama", {35.114027,139.833394}},
  {523956172, "Iwaieki", {35.09328,139.849893}},
  {523936984, "Tateyama", {34.995957,139.861896}},
  {524050283, "Kamogawa", {34.995957,139.861896}},
  {524052842, "Katsuura", {35.152563,140.311936}},
  {524062283, "Mishuku", {35.18756,140.351431}},
  {524073011, "Ohara", {35.251221,140.391036}},
  {534002493, "Ichinomiya", {35.373089,140.369527}},
  {534012141, "Shigehara", {35.426874,140.304048}},
  {534022244, "Ohami", {35.452607,140.282762}},
  {534023451, "Kujuukuri", {35.522631,140.310999}},
  {534022791, "Tougane", {35.560158,140.363609}},
  {534033322, "Naritou", {35.608387,140.410859}},
  {534033991, "Yokoshiba", {35.661769,140.491232}},
  {534044343, "Youkaichi", {35.699286,140.552366}},
  {534043331, "Shibayamacho", {35.693126,140.414397}},
  {534032953, "Yachimata", {35.644488,140.301338}},
  {534031933, "Yotsukido", {35.644488,140.301338}},
  {534041503, "Katsutadai", {35.715438,140.125972}},
  {534041721, "Chikucentereki", {35.725856,140.155287}},
  {534042723, "Sakesakai", {35.731664,140.275249}},
  {534042771, "Miyazato", {35.726649,140.346981}},
  {534043871, "Takocho", {35.726649,140.346981}},
  {534053104, "Narita", {35.771987,140.39285}},
  {534045623, "Asahi", {35.722009,140.654939}},
  {534046763, "Choushi", {35.751212,140.7845}},
  {534055861, "ShimousaTachibana", {35.780462,140.744675}},
  {534061091, "Ajikieki", {35.835707,140.242358}},
  {534050691, "ChibaNewtown", {35.800133,140.116274}},
  {534050422, "Nishishiraieki", {35.784402,140.031767}},
  {533957392, "Kamagaya", {35.779409,139.998398}},
  {533957421, "Matsudo", {35.7843,139.900661}},
  {533967372, "Kashiwa", {35.86215,139.970917}},
  {534060404, "Abiko", {35.872703,140.010794}},
  {533967443, "Nagareyama", {35.871905,139.925241}},
  {533976491, "Atagoeki", {35.950148,139.864819}},
  {533976151, "Matsubushicho", {35.922758,139.815748}},
#endif  
};

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
    static set<string> retry;
    if (retry.find(fn) != retry.end()) {
      cerr << os.str() << " failed\n";
      return true;
    }
    retry.insert(fn);
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

int main()
{
  using namespace std;
  pid_t pid = fork();
  if (!pid) {
    ostringstream os;
    execl("/usr/bin/firefox", "firefox",
	  "https://tokyo.mobakumap.jp/", nullptr);
    cerr << "execl failed\n";
    return 1;
  }
  sleep(30);
  auto p = find_if(begin(data), end(data), subr);
  return end(data) - p;
}
