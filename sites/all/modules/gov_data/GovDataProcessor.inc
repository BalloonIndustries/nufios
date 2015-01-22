<?php

class GovDataProcessor extends FeedsProcessor {
  /**
   * Required methods:
   * - entityType()
   * - newEntity(FeedsSource $source)
   * - entityLoad(FeedsSource $source, $entity_id)
   * - entitySave($entity)
   * - entityDeleteMultiple($entity_ids)
   */

  /**
   * File: MyProcessor.inc
   * Class: MyProcessor
   */
  public function entityType() {
    return 'gov_data';
  }

  public function newEntity(FeedsSource $source) {
    $gov_data = new stdClass();
    $gov_data->gid = 0;
    $gov_data->type = '';
    $gov_data->bid = '';
    return $gov_data;
  }

  /**
   * File: MyProcessor.inc
   * Class: MyProcessor
   */
  public function entityLoad(FeedsSource $source, $entity_id) {
    return entity_load("gov_data", $entity_id);
  }

  public function entitySave($entity) {
    entity_save("gov_data", $entity);
  }

  public function entityDeleteMultiple($entity_ids) {
    entity_delete_multiple("gov_data", $entity_ids);
  }

  /**
   * File: MyProcessor.inc
   * Class: MyProcessor
   */
  public function getMappingTargets() {
    return array(
      'gid' => array(
        'name' => t('ID of my entity'),
        'description' => t('This ID is unique identifier for my entity.'),
        'optional_unique' => TRUE,
      ),
      'type' => array(
        'name' => t('Type'),
        'description' => t('Bundle type of the entity.'),
      ),
      'bid' => array(
        'name' => t('Bundle ID'),
        'description' => t('Bundle ID of the entity.'),
      ),
    );
  }

}