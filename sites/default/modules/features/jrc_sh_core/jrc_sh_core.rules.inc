<?php

/**
 * @file
 * Custom Rules action for Organic Groups.
 */

/**
 * Implements hook_rules_action_info().
 */
function jrc_sh_core_rules_action_info() {
  return array(
    '_jrc_sh_core_set_issues_from_research_topics' => array(
      'label' => t('Get the equivalent issues from research topics'),
      'group' => t('custom'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
          'description' => t('The nodes.'),
        ),
      ),
    ),
  );
}

/**
 * Set the related Issues keys to the node from the matched research topics.
 *
 * @param object $node
 *   The given node.
 */
function _jrc_sh_core_set_issues_from_research_topics($node) {
  $list_of_matched_issues = array();
  if (count($node->field_related_topics[LANGUAGE_NONE])) {
    foreach ($node->field_related_topics[LANGUAGE_NONE] as $old_research_topic) {
      $new_issue_matches = _jrc_sh_core_get_issues_from_a_research_topic($old_research_topic['target_id']);
      $list_of_matched_issues = array_unique(array_merge($new_issue_matches, $list_of_matched_issues));
    }
  }
  foreach ($list_of_matched_issues as $key => $value) {
    $list_of_matched_issues[$key] = array('target_id' => $value);
  }
  $node->field_related_topics_nexus_issue[LANGUAGE_NONE] = $list_of_matched_issues;
  field_attach_update('node', $node);
}

/**
 * Get the related Issues keys from the node's research topics.
 *
 * @param int $research_topic_id
 *   An old research topic's id.
 *
 * @return array
 *   Returns the matched issues.
 */
function _jrc_sh_core_get_issues_from_a_research_topic($research_topic_id) {
  $old_new_match = array(
    113021 => array(
      "name" => "Life Cycle Indicators and Data",
      "issues" => array(),
    ),
    113022 => array(
      "name" => "Product Environmental Footprint (PEF) and Organisation Environmental Footprint (OEF)",
      "issues" => array(),
    ),
    113023 => array(
      "name" => "Material efficiency of products for the circular economy",
      "issues" => array(),
    ),
    113024 => array(
      "name" => "Circular economy â€“ Waste management",
      "issues" => array(),
    ),
    113025 => array(
      "name" => "Critical raw material â€“ Life cycle approaches",
      "issues" => array(),
    ),
    113026 => array(
      "name" => "Eco-innovation in supply chains",
      "issues" => array(),
    ),
    113027 => array(
      "name" => "Land Use-based Integrated Sustainability Assessment Modelling",
      "issues" => array(),
    ),
    113028 => array(
      "name" => "Regional Dimension of Sustainable Development",
      "issues" => array(),
    ),
    113029 => array(
      "name" => "Economic Modelling, Scenarios and Impact Assessments",
      "issues" => array(),
    ),
    113030 => array(
      "name" => "Integrated Assessments for a Sustainable Bio-economy",
      "issues" => array(),
    ),
    113031 => array(
      "name" => "International Avogadro constant project",
      "issues" => array(),
    ),
    113032 => array(
      "name" => "Acrylamide",
      "issues" => array(),
    ),
    113033 => array(
      "name" => "Isotopic calibrants for osteoporosis research",
      "issues" => array(),
    ),
    113034 => array(
      "name" => "Melamine",
      "issues" => array(),
    ),
    113035 => array(
      "name" => "Smoke flavourings",
      "issues" => array(),
    ),
    113036 => array(
      "name" => "Allergens",
      "issues" => array(),
    ),
    113037 => array(
      "name" => "Meat and bone meal",
      "issues" => array(),
    ),
    113038 => array(
      "name" => "Marker for animal by-products",
      "issues" => array(),
    ),
    113039 => array(
      "name" => "Natural toxins (Mycotoxins)",
      "issues" => array(),
    ),
    113040 => array(
      "name" => "Phthalates",
      "issues" => array(),
    ),
    113041 => array(
      "name" => "TSE testing",
      "issues" => array(),
    ),
    113042 => array(
      "name" => "Veterinary drugs in feed",
      "issues" => array(),
    ),
    113043 => array(
      "name" => "Functional foods including substances with antioxidative effects",
      "issues" => array(),
    ),
    113044 => array(
      "name" => "Food additives",
      "issues" => array(),
    ),
    113045 => array(
      "name" => "Isotopes for improved management of Nitrate Pollution in Aqueous Resources (INPAR network)",
      "issues" => array(),
    ),
    113046 => array(
      "name" => "Farming in the EU",
      "issues" => array(
        184246,
      ),
    ),
    113047 => array(
      "name" => "Chemical, biological, radiological and nuclear hazards",
      "issues" => array(
        184241,
        184255,
        184256,
        184257,
        184258,
        184259,
      ),
    ),
    113048 => array(
      "name" => "Energy technology & innovation",
      "issues" => array(
        184228,
        184230,
        184235,
        184246,
        184271,
      ),
    ),
    113049 => array(
      "name" => "Rural development",
      "issues" => array(
        184252,
        184264,
        184265,
      ),
    ),
    113050 => array(
      "name" => "Security for privacy and data protection",
      "issues" => array(
        184229,
        184257,
        184260,
        184262,
        184266,
      ),
    ),
    113051 => array(
      "name" => "Battery Energy Storage Testing",
      "issues" => array(),
    ),
    113052 => array(
      "name" => "Energy efficiency",
      "issues" => array(
        184229,
        184230,
        184235,
      ),
    ),
    113053 => array(
      "name" => "Alternatives to animal testing and safety assessment of chemicals",
      "issues" => array(
        184241,
        184244,
      ),
    ),
    113054 => array(
      "name" => "Renewable energy",
      "issues" => array(
        184226,
        184228,
        184229,
        184231,
        184234,
        184235,
        184247,
      ),
    ),
    113055 => array(
      "name" => "Agricultural markets and international trade",
      "issues" => array(
        184223,
        184227,
      ),
    ),
    113056 => array(
      "name" => "Global food security",
      "issues" => array(
        184240,
        184249,
      ),
    ),
    113057 => array(
      "name" => "Marine modelling",
      "issues" => array(),
    ),
    113058 => array(
      "name" => "Surveillance",
      "issues" => array(
        184233,
        184255,
        184256,
        184257,
        184258,
        184260,
        184261,
      ),
    ),
    113059 => array(
      "name" => "Antifraud",
      "issues" => array(
        184223,
        184224,
        184226,
        184257,
      ),
    ),
    113060 => array(
      "name" => "Crisis management",
      "issues" => array(
        184223,
        184232,
        184255,
        184256,
        184257,
      ),
    ),
    113061 => array(
      "name" => "Global safety and security",
      "issues" => array(
        184232,
        184241,
        184255,
        184256,
        184257,
        184258,
        184259,
        184261,
        184263,
      ),
    ),
    113062 => array(
      "name" => "Preparedness for radiological emergencies",
      "issues" => array(
        184232,
        184255,
        184258,
        184259,
      ),
    ),
    113063 => array(
      "name" => "Nuclear safeguards and security",
      "issues" => array(
        184241,
        184255,
        184258,
        184261,
      ),
    ),
    113064 => array(
      "name" => "Nuclear safety",
      "issues" => array(
        184232,
        184255,
      ),
    ),
    113065 => array(
      "name" => "Earth observation",
      "issues" => array(),
    ),
    113066 => array(
      "name" => "Cybersecurity",
      "issues" => array(
        184229,
        184251,
        184260,
        184261,
        184262,
        184266,
      ),
    ),
    113067 => array(
      "name" => "GMOs",
      "issues" => array(
        184240,
      ),
    ),
    113068 => array(
      "name" => "Food and feed safety",
      "issues" => array(),
    ),
    113069 => array(
      "name" => "Natural and man-made hazards",
      "issues" => array(
        184256,
        184263,
      ),
    ),
    113070 => array(
      "name" => "Ecosystems and biodiversity",
      "issues" => array(
        184247,
        184248,
      ),
    ),
    113071 => array(
      "name" => "Coastal and marine environment",
      "issues" => array(
        184250,
        184248,
      ),
    ),
    113072 => array(
      "name" => "Soil",
      "issues" => array(
        184247,
      ),
    ),
    113073 => array(
      "name" => "Nuclear science base for standardisation",
      "issues" => array(
        184232,
      ),
    ),
    113074 => array(
      "name" => "Transport safety and security",
      "issues" => array(
        184234,
        184261,
      ),
    ),
    113075 => array(
      "name" => "Food authenticity and quality",
      "issues" => array(
        184240,
        184242,
      ),
    ),
    113076 => array(
      "name" => "Financial and economic analysis",
      "issues" => array(
        184223,
      ),
    ),
    113077 => array(
      "name" => "Certified reference materials",
      "issues" => array(
        184244,
      ),
    ),
    113078 => array(
      "name" => "Water",
      "issues" => array(
        184247,
      ),
    ),
    113079 => array(
      "name" => "Sustainable production and consumption",
      "issues" => array(
        184225,
        184246,
      ),
    ),
    113080 => array(
      "name" => "Agricultural technological innovation",
      "issues" => array(
        184240,
        184246,
      ),
    ),
    113081 => array(
      "name" => "Digital Society",
      "issues" => array(),
    ),
    113082 => array(
      "name" => "Critical infrastructure protection ",
      "issues" => array(),
    ),
    113085 => array(
      "name" => "Digital Earth",
      "issues" => array(
        184245,
        184266,
        184269,
        184275,
      ),
    ),
    113086 => array(
      "name" => "Bioinformatics",
      "issues" => array(),
    ),
    113087 => array(
      "name" => "Counterfactual impact evaluation",
      "issues" => array(
        184252,
      ),
    ),
    113088 => array(
      "name" => "Education and Lifelong Learning",
      "issues" => array(
        184236,
        184237,
        184251,
        184274,
      ),
    ),
    113089 => array(
      "name" => "Human exposure",
      "issues" => array(
        184241,
        184243,
      ),
    ),
    113090 => array(
      "name" => "Interoperability of Global Navigation Satellite Systems",
      "issues" => array(
        184269,
      ),
    ),
    113091 => array(
      "name" => "Public health",
      "issues" => array(
        184236,
        184241,
        184242,
        184243,
      ),
    ),
    113092 => array(
      "name" => "Transport sector economic analysis",
      "issues" => array(
        184234,
      ),
    ),
    113093 => array(
      "name" => "Sustainable transport and fuels",
      "issues" => array(
        184229,
        184230,
        184234,
      ),
    ),
    113094 => array(
      "name" => "Nuclear knowledge management, training and education",
      "issues" => array(
        184258,
      ),
    ),
    113095 => array(
      "name" => "Integrated sustainability assessments",
      "issues" => array(
        184226,
        184246,
        184265,
      ),
    ),
    113096 => array(
      "name" => "Fisheries and Aquaculture",
      "issues" => array(
        184240,
        184247,
        184248,
      ),
    ),
    113097 => array(
      "name" => "Environmental monitoring",
      "issues" => array(
        184232,
        184241,
        184245,
        184248,
        184258,
      ),
    ),
    113098 => array(
      "name" => "Consumption Patterns and Sustainability",
      "issues" => array(),
    ),
    113099 => array(
      "name" => "Green and circular economy",
      "issues" => array(
        184225,
        184226,
        184230,
        184240,
        184246,
      ),
    ),
    113100 => array(
      "name" => "Industrial research and innovation",
      "issues" => array(
        184225,
        184269,
        184271,
      ),
    ),
    113101 => array(
      "name" => "Nanotechnology",
      "issues" => array(
        184241,
        184243,
      ),
    ),
    113102 => array(
      "name" => "Nuclear energy",
      "issues" => array(
        184229,
        184232,
      ),
    ),
    113103 => array(
      "name" => "Composite indicators",
      "issues" => array(
        184274,
      ),
    ),
    113104 => array(
      "name" => "Impacts of climate change",
      "issues" => array(
        184245,
        184250,
      ),
    ),
    113105 => array(
      "name" => "Crop yield forecasting",
      "issues" => array(
        184247,
      ),
    ),
    113106 => array(
      "name" => "Research and innovation policies",
      "issues" => array(
        184271,
        184272,
      ),
    ),
    113107 => array(
      "name" => "Forestry",
      "issues" => array(
        184247,
        184248,
      ),
    ),
    113108 => array(
      "name" => "Employability and social inclusion",
      "issues" => array(
        184224,
        184226,
        184237,
        184238,
        184251,
        184252,
        184253,
        184263,
        184264,
        184265,
      ),
    ),
    113109 => array(
      "name" => "Energy sector economic analysis",
      "issues" => array(
        184223,
        184229,
        184230,
        184231,
        184235,
      ),
    ),
    113110 => array(
      "name" => "Climate change",
      "issues" => array(
        184250,
        184263,
      ),
    ),
    113111 => array(
      "name" => "Smart specialisation",
      "issues" => array(
        184225,
        184265,
        184271,
        184273,
      ),
    ),
    113112 => array(
      "name" => "Agricultural monitoring",
      "issues" => array(
        184240,
        184248,
      ),
    ),
    113113 => array(
      "name" => "Digital Innovation",
      "issues" => array(),
    ),
    113114 => array(
      "name" => "Digital Living",
      "issues" => array(
        184225,
        184229,
        184236,
        184251,
        184260,
        184262,
        184268,
        184269,
        184275,
      ),
    ),
    113115 => array(
      "name" => "Agricultural biodiversity",
      "issues" => array(
        184246,
        184247,
      ),
    ),
    113116 => array(
      "name" => "Atmospheric dispersion",
      "issues" => array(
        184243,
        184256,
        184258,
      ),
    ),
    113117 => array(
      "name" => "Aviation safety",
      "issues" => array(
        184234,
        184261,
      ),
    ),
    113118 => array(
      "name" => "Citizens' digital footprint",
      "issues" => array(
        184251,
        184257,
        184260,
        184266,
        184268,
      ),
    ),
    113119 => array(
      "name" => "Aviation security",
      "issues" => array(
        184234,
        184255,
        184261,
      ),
    ),
    113120 => array(
      "name" => "Behaviour and ICT policy",
      "issues" => array(
        184268,
        184270,
      ),
    ),
    113121 => array(
      "name" => "Best environmental management practice",
      "issues" => array(
        184240,
        184247,
      ),
    ),
    113122 => array(
      "name" => "Biofuels and bioenergy",
      "issues" => array(
        184228,
        184229,
        184235,
      ),
    ),
    113123 => array(
      "name" => "Clearinghouse",
      "issues" => array(
        184232,
        184233,
        184258,
        184259,
        184261,
      ),
    ),
    113124 => array(
      "name" => "Combating illicit trafficking",
      "issues" => array(
        184257,
        184258,
        184259,
      ),
    ),
    113125 => array(
      "name" => "Consumer products",
      "issues" => array(
        184240,
        184241,
        184242,
      ),
    ),
    113126 => array(
      "name" => "Costs and benefits of climate policies ",
      "issues" => array(
        184235,
        184245,
      ),
    ),
    113127 => array(
      "name" => "Climate change mitigation",
      "issues" => array(
        184250,
      ),
    ),
    113128 => array(
      "name" => "Disaster risk management",
      "issues" => array(
        184232,
        184256,
      ),
    ),
    113129 => array(
      "name" => "Desertification and drought",
      "issues" => array(
        184247,
        184248,
        184249,
        184263,
      ),
    ),
    113130 => array(
      "name" => "Earth observation products",
      "issues" => array(
        184245,
        184256,
      ),
    ),
    113131 => array(
      "name" => "Data exchange standardisation for maritime surveillance",
      "issues" => array(
        184261,
      ),
    ),
    113132 => array(
      "name" => "Earthquakes and tsunamis",
      "issues" => array(
        184256,
        184261,
      ),
    ),
    113133 => array(
      "name" => "Economic, environmental and social effects of globalisation",
      "issues" => array(
        184238,
        184253,
        184263,
      ),
    ),
    113134 => array(
      "name" => "Emergency support â€“ international data and information exchange systems",
      "issues" => array(),
    ),
    113135 => array(
      "name" => "Emergency support â€“ radioecological monitoring",
      "issues" => array(),
    ),
    113136 => array(
      "name" => "Energy - Transparency Centre of Knowledge (E-TRACK)",
      "issues" => array(
        184231,
        184235,
      ),
    ),
    113137 => array(
      "name" => "Ethical aspects of new ICT technologies",
      "issues" => array(
        184260,
        184275,
      ),
    ),
    113138 => array(
      "name" => "Financial Analysis",
      "issues" => array(),
    ),
    113139 => array(
      "name" => "Fires",
      "issues" => array(
        184256,
      ),
    ),
    113140 => array(
      "name" => "Foreign fats in chocolate",
      "issues" => array(),
    ),
    113141 => array(
      "name" => "Food contact materials",
      "issues" => array(
        184240,
        184249,
      ),
    ),
    113142 => array(
      "name" => "Floods",
      "issues" => array(
        184256,
      ),
    ),
    113143 => array(
      "name" => "Healthcare quality",
      "issues" => array(
        184241,
        184242,
        184243,
      ),
    ),
    113144 => array(
      "name" => "Forest adaptation to climate change",
      "issues" => array(
        184250,
      ),
    ),
    113145 => array(
      "name" => "Genetics for traceability in the fisheries sector",
      "issues" => array(
        184249,
      ),
    ),
    113146 => array(
      "name" => "Global health security and support",
      "issues" => array(
        184241,
        184243,
        184244,
      ),
    ),
    113147 => array(
      "name" => "Fundamental properties of actinide materials",
      "issues" => array(
        184232,
        184271,
      ),
    ),
    113148 => array(
      "name" => "Hydrogen and fuel cells",
      "issues" => array(
        184228,
        184229,
        184234,
        184247,
      ),
    ),
    113149 => array(
      "name" => "Hazards and risks of climate change impacts",
      "issues" => array(
        184245,
        184250,
      ),
    ),
    113150 => array(
      "name" => "Governance, public sector innovation and social change",
      "issues" => array(
        184223,
        184238,
        184251,
        184252,
        184253,
        184254,
        184271,
      ),
    ),
    113151 => array(
      "name" => "Input-output economics",
      "issues" => array(
        184223,
        184224,
        184225,
        184226,
        184227,
        184252,
        184263,
      ),
    ),
    113152 => array(
      "name" => "Interoperability and e-mobility",
      "issues" => array(
        184228,
        184229,
        184234,
      ),
    ),
    113153 => array(
      "name" => "Macroeconomic analysis for monitoring EU economic stance",
      "issues" => array(
        184223,
        184226,
        184227,
      ),
    ),
    113154 => array(
      "name" => "Maritime safety and security",
      "issues" => array(
        184234,
        184255,
      ),
    ),
    113155 => array(
      "name" => "Measuring research and innovation",
      "issues" => array(
        184265,
        184271,
      ),
    ),
    113156 => array(
      "name" => "Metrological tools for safeguard activities",
      "issues" => array(
        184256,
      ),
    ),
    113157 => array(
      "name" => "Monitoring container traffic and analysing risk",
      "issues" => array(
        184234,
        184257,
      ),
    ),
    113158 => array(
      "name" => "Monitoring fiscal imbalances",
      "issues" => array(
        184223,
        184226,
      ),
    ),
    113159 => array(
      "name" => "Monitoring of climate and climate change",
      "issues" => array(
        184245,
        184250,
      ),
    ),
    113160 => array(
      "name" => "Improving safety in construction",
      "issues" => array(
        184243,
      ),
    ),
    113161 => array(
      "name" => "Internet surveillance systems",
      "issues" => array(
        184256,
        184257,
        184260,
        184261,
      ),
    ),
    113162 => array(
      "name" => "Maritime surveillance",
      "issues" => array(
        184247,
        184256,
        184257,
      ),
    ),
    113163 => array(
      "name" => "Medical applications of radionuclides and targeted alpha therapy",
      "issues" => array(
        184241,
        184243,
        184244,
      ),
    ),
    113164 => array(
      "name" => "Learning and Skills for the Digital Era",
      "issues" => array(
        184225,
        184236,
        184237,
        184251,
        184266,
        184267,
        184268,
      ),
    ),
    113165 => array(
      "name" => "Natural radiation",
      "issues" => array(
        184232,
        184241,
      ),
    ),
    113166 => array(
      "name" => "Nuclear data measurement program ",
      "issues" => array(),
    ),
    113167 => array(
      "name" => "Non-proliferation",
      "issues" => array(
        184258,
        184259,
      ),
    ),
    113168 => array(
      "name" => "Nuclear accident modelling",
      "issues" => array(
        184232,
        184255,
        184258,
      ),
    ),
    113169 => array(
      "name" => "Nuclear fuel safety",
      "issues" => array(
        184232,
      ),
    ),
    113170 => array(
      "name" => "Nuclear materials under extreme conditions",
      "issues" => array(
        184232,
      ),
    ),
    113171 => array(
      "name" => "Nuclear reference data, materials and measurements",
      "issues" => array(
        184258,
      ),
    ),
    113172 => array(
      "name" => "Nuclear safeguards",
      "issues" => array(),
    ),
    113173 => array(
      "name" => "Nuclear waste management and decommissioning",
      "issues" => array(
        184232,
      ),
    ),
    113174 => array(
      "name" => "Nutrition",
      "issues" => array(
        184240,
        184242,
      ),
    ),
    113175 => array(
      "name" => "Ocean Colour: Essential climate variables",
      "issues" => array(
        184245,
        184250,
      ),
    ),
    113176 => array(
      "name" => "Organic food and sustainable agriculture",
      "issues" => array(
        184240,
        184242,
        184246,
        184249,
      ),
    ),
    113177 => array(
      "name" => "Photovoltaics",
      "issues" => array(
        184228,
        184230,
      ),
    ),
    113178 => array(
      "name" => "Piracy, maritime awareness and risks",
      "issues" => array(
        184255,
        184257,
        184261,
      ),
    ),
    113179 => array(
      "name" => "Preventing industrial accidents",
      "issues" => array(
        184255,
        184256,
      ),
    ),
    113180 => array(
      "name" => "Primary isotopic measurements",
      "issues" => array(),
    ),
    113181 => array(
      "name" => "Railways safety",
      "issues" => array(
        184234,
        184261,
      ),
    ),
    113182 => array(
      "name" => "Reactor safety",
      "issues" => array(
        184232,
        184261,
      ),
    ),
    113183 => array(
      "name" => "Reference materials for food analysis",
      "issues" => array(
        184240,
      ),
    ),
    113184 => array(
      "name" => "Reference materials for fuel analysis",
      "issues" => array(
        184228,
        184234,
      ),
    ),
    113185 => array(
      "name" => "Reference materials for clinical analysis",
      "issues" => array(
        184241,
        184244,
      ),
    ),
    113186 => array(
      "name" => "Reference materials for GMO analysis",
      "issues" => array(
        184240,
        184241,
      ),
    ),
    113187 => array(
      "name" => "Reference materials for materials science",
      "issues" => array(
        184247,
      ),
    ),
    113188 => array(
      "name" => "Reference materials for nanotechnologies",
      "issues" => array(),
    ),
    113189 => array(
      "name" => "Reference materials for microbiology and natural toxins",
      "issues" => array(),
    ),
    113190 => array(
      "name" => "Reference materials for nuclear safeguards, safety and security",
      "issues" => array(
        184232,
        184258,
        184259,
      ),
    ),
    113191 => array(
      "name" => "Regional economic analysis and modelling",
      "issues" => array(
        184223,
        184265,
      ),
    ),
    113192 => array(
      "name" => "Radioactive waste management (E-TraCK-RWM)",
      "issues" => array(
        184232,
      ),
    ),
    113193 => array(
      "name" => "Reference materials for environmental analysis",
      "issues" => array(),
    ),
    113194 => array(
      "name" => "Radioactive environmental monitoring",
      "issues" => array(
        184232,
        184258,
      ),
    ),
    113195 => array(
      "name" => "Road safety: the digital tachograph",
      "issues" => array(
        184234,
        184261,
      ),
    ),
    113196 => array(
      "name" => "Science and technology studies",
      "issues" => array(
        184236,
        184269,
        184271,
        184272,
        184273,
        184275,
      ),
    ),
    113197 => array(
      "name" => "Sensitivity analysis, sensitivity auditing and impact assessment",
      "issues" => array(
        184223,
        184271,
      ),
    ),
    113198 => array(
      "name" => "Soil protection",
      "issues" => array(
        184247,
        184248,
      ),
    ),
    113199 => array(
      "name" => "Security of the supply chain",
      "issues" => array(
        184257,
        184261,
      ),
    ),
    113200 => array(
      "name" => "Safe mobility for the visually impaired",
      "issues" => array(),
    ),
    113201 => array(
      "name" => "Stairway to Excellence (S2E)",
      "issues" => array(
        184225,
        184265,
        184271,
        184273,
      ),
    ),
    113202 => array(
      "name" => "Radio spectrum and wireless services",
      "issues" => array(
        184269,
      ),
    ),
    113203 => array(
      "name" => "Standards in construction: the Eurocodes",
      "issues" => array(
        184224,
      ),
    ),
    113204 => array(
      "name" => "Strengthening transparency in aid: EU Aid Explorer",
      "issues" => array(
        184255,
      ),
    ),
    113205 => array(
      "name" => "Structural materials for nuclear applications",
      "issues" => array(
        184232,
      ),
    ),
    113206 => array(
      "name" => "Space technologies for disaster risk reduction and response",
      "issues" => array(
        184255,
        184256,
      ),
    ),
    113207 => array(
      "name" => "Sustainability of climate policies",
      "issues" => array(
        184250,
      ),
    ),
    113208 => array(
      "name" => "Sustainable Product Policy",
      "issues" => array(
        184225,
      ),
    ),
    113209 => array(
      "name" => "Sustainable production: best available techniques",
      "issues" => array(
        184225,
        184228,
        184229,
        184230,
        184231,
        184246,
      ),
    ),
    113210 => array(
      "name" => "Sustainable management of natural resources in ACP countries",
      "issues" => array(
        184247,
      ),
    ),
    113211 => array(
      "name" => "Technological accidents triggered by natural disasters",
      "issues" => array(
        184256,
      ),
    ),
    113212 => array(
      "name" => "Waste and Circular Economy",
      "issues" => array(
        184246,
      ),
    ),
    113213 => array(
      "name" => "Water governance",
      "issues" => array(
        184247,
      ),
    ),
    113214 => array(
      "name" => "Water biodiversity",
      "issues" => array(
        184247,
        184248,
      ),
    ),
    113215 => array(
      "name" => "Economics of the Digital Single Market ",
      "issues" => array(
        184224,
        184231,
      ),
    ),
    113216 => array(
      "name" => "Air quality and greenhouse gases",
      "issues" => array(
        184248,
      ),
    ),
    113217 => array(
      "name" => "Digital Economy",
      "issues" => array(
        184224,
        184225,
        184238,
        184267,
        184268,
        184269,
        184270,
        184275,
      ),
    ),
    113218 => array(
      "name" => "Big Data",
      "issues" => array(),
    ),
    113219 => array(
      "name" => "ICT industry and ICT R&D in Europe",
      "issues" => array(
        184224,
        184225,
        184266,
        184267,
        184268,
        184269,
      ),
    ),
    113220 => array(
      "name" => "Energy security, distribution and markets",
      "issues" => array(),
    ),
    113221 => array(
      "name" => "European Human Resources Observatory for the Nuclear Energy Sector (EHRO-N)",
      "issues" => array(
        184232,
        184257,
        184258,
        184259,
      ),
    ),
    113222 => array(
      "name" => "Accident prevention",
      "issues" => array(
        184232,
        184241,
        184243,
        184256,
      ),
    ),
    174658 => array(
      "name" => "Fiscal policy analysis",
      "issues" => array(
        184223,
        184226,
      ),
    ),
    174923 => array(
      "name" => "Quantum technologies  ",
      "issues" => array(),
    ),
    175012 => array(
      "name" => "Carbon capture, use and storage",
      "issues" => array(),
    ),
    175458 => array(
      "name" => "Raw materials",
      "issues" => array(
        184228,
        184247,
      ),
    ),
    176397 => array(
      "name" => "Carbon capture, utilisation and storage",
      "issues" => array(
        184228,
        184231,
        184235,
      ),
    ),
    180127 => array(
      "name" => "Innovation & Entrepreneurship in the Digital Economy",
      "issues" => array(),
    ),
    183672 => array(
      "name" => "Energy Storage",
      "issues" => array(),
    ),
    183832 => array(
      "name" => "Sustainable Finance",
      "issues" => array(),
    ),
    183833 => array(
      "name" => "Capital markets and cross-border investments",
      "issues" => array(),
    ),
    183834 => array(
      "name" => "Banking regulation and systemic risk",
      "issues" => array(),
    ),
  );

  return $old_new_match[$research_topic_id]['issues'];
}
