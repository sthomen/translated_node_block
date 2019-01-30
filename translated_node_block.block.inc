<?php
/**
 * @file
 * Extend the NodeBlock class to find the appropriate translation of a node,
 * if available.
 */

class TranslatedNodeBlock extends NodeBlock {
  function getAdminTitle() {
    return t('Existing content (translated)');
  }

  function prepare() {
    $this->settings['nid'] = $this->findTranslation($this->settings['nid']);
  }

  function findTranslation($nid) {
    global $language;

    $node = node_load($nid);

    if (empty($node->tnid) || empty($node->langcode)) {
      return $nid;
	}

    $translations = translation_node_get_translations($node->tnid);

    foreach ($translations as $code => $translation) {
      if ($code == $language->langcode) {
        return $translation->nid;
      }
    }

    return $nid;
  }
}
